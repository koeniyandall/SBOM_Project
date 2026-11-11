#!/usr/bin/env python3
"""
sbom_candidates.py - Send Ghidra decompiler output + strings to Claude and get
SBOM component candidates (library name, version, evidence, confidence).

Usage:
  export ANTHROPIC_API_KEY=sk-ant-...
  python3 sbom_candidates.py firmware.elf \
      --decomp decomp.c \
      --strings-script ./extract_strings.sh \
      --out candidates.json --cyclonedx sbom.cdx.json

Requires: pip install anthropic
"""

import argparse
import json
import os
import re
import subprocess
import sys
import uuid
from datetime import datetime, timezone
from pathlib import Path

try:
    import anthropic
except ImportError:
    sys.exit("Missing dependency: pip install anthropic")

DEFAULT_MODEL = "claude-sonnet-5-5"

# Strings that are likely to identify a component get priority when the
# strings output has to be trimmed to fit the budget.
INTERESTING = re.compile(
    r"(\bv?\d+\.\d+(\.\d+)*\b|copyright|\(c\)|version|license|gpl|bsd|mit\b|"
    r"apache|lib[a-z0-9_]+|newlib|freertos|zephyr|lwip|mbed|tinycrypt|wolfssl|"
    r"openssl|zlib|fatfs|cmsis|hal_|stm32|nrf|esp-idf|arm|gcc|build|rtos|"
    r"error|assert|\.c\b|\.h\b)",
    re.IGNORECASE,
)

SYSTEM_PROMPT = """You are a firmware reverse-engineering assistant building a \
Software Bill of Materials (SBOM) for a compiled binary.

You are given (1) printable strings extracted from the binary and (2) Ghidra \
decompiler output (possibly one chunk of a larger file). Identify third-party \
software components (libraries, RTOSes, SDKs, HALs, crypto/compression/network \
stacks, C runtime) compiled into the binary.

Rules:
- Only report components supported by concrete evidence in the input: version \
strings, copyright/license banners, unique error/log messages, characteristic \
function names, magic constants (e.g. CRC/SHA tables), or recognizable algorithm \
structure.
- Quote the exact evidence (string text or function name/address) for every \
candidate. Do not invent evidence.
- Give a version only if the evidence supports it; otherwise leave version empty. \
If you can narrow it to a range, put that in version_notes.
- confidence: "high" = explicit name/version string or banner; "medium" = several \
characteristic functions/constants; "low" = a single weak indicator.
- Do not report the compiler toolchain itself as a component unless runtime \
library code (e.g. newlib, libgcc, compiler-rt) is actually linked in.
- If nothing is identifiable, return an empty list.
Always respond by calling the report_candidates tool."""

TOOL = {
    "name": "report_candidates",
    "description": "Report the software components identified in the binary.",
    "input_schema": {
        "type": "object",
        "properties": {
            "candidates": {
                "type": "array",
                "items": {
                    "type": "object",
                    "properties": {
                        "name": {"type": "string", "description": "Component name, e.g. 'newlib-nano'"},
                        "version": {"type": "string", "description": "Exact version if supported by evidence, else ''"},
                        "version_notes": {"type": "string", "description": "Range or reasoning about version"},
                        "type": {"type": "string", "enum": ["library", "rtos", "sdk", "runtime", "framework", "other"]},
                        "purl": {"type": "string", "description": "Package URL if determinable, else ''"},
                        "license": {"type": "string", "description": "SPDX id if evidenced, else ''"},
                        "confidence": {"type": "string", "enum": ["high", "medium", "low"]},
                        "evidence": {
                            "type": "array",
                            "items": {
                                "type": "object",
                                "properties": {
                                    "kind": {"type": "string", "enum": ["string", "function", "constant", "code_pattern"]},
                                    "value": {"type": "string"},
                                    "location": {"type": "string", "description": "Address or function name, if known"},
                                },
                                "required": ["kind", "value"],
                            },
                        },
                    },
                    "required": ["name", "version", "type", "confidence", "evidence"],
                },
            },
            "notes": {"type": "string", "description": "Anything uncertain worth a human look"},
        },
        "required": ["candidates"],
    },
}

CONF_RANK = {"low": 0, "medium": 1, "high": 2}


# ---------------------------------------------------------------- inputs

def get_strings(binary: Path, strings_script: Path | None, min_len: int) -> list[str]:
    if strings_script:
        cmd = ["bash", str(strings_script), str(binary)]
    else:
        cmd = ["strings", "-a", "-n", str(min_len), str(binary)]
    res = subprocess.run(cmd, capture_output=True, text=True, errors="replace")
    if res.returncode != 0:
        sys.exit(f"strings step failed ({' '.join(cmd)}):\n{res.stderr}")
    lines = [l.rstrip() for l in res.stdout.splitlines()]
    # Drop the banner line your script prints, and dedupe while keeping order.
    lines = [l for l in lines if l and not l.startswith("=== Extracting printable strings")]
    return list(dict.fromkeys(lines))


def fit_strings(strings: list[str], budget: int) -> tuple[str, int]:
    """Return strings joined under budget chars, prioritizing interesting ones."""
    full = "\n".join(strings)
    if len(full) <= budget:
        return full, 0
    hot = [s for s in strings if INTERESTING.search(s)]
    cold = [s for s in strings if not INTERESTING.search(s)]
    kept, size = [], 0
    for s in hot + cold:
        if size + len(s) + 1 > budget:
            continue
        kept.append(s)
        size += len(s) + 1
    kept_set = set(kept)
    ordered = [s for s in strings if s in kept_set]  # preserve original order
    return "\n".join(ordered), len(strings) - len(ordered)


def chunk_decomp(text: str, budget: int) -> list[str]:
    """Split decompiler output into chunks at blank-line (function) boundaries."""
    if len(text) <= budget:
        return [text]
    blocks = re.split(r"\n\s*\n", text)
    chunks, cur = [], ""
    for b in blocks:
        while len(b) > budget:  # a single giant function: hard split
            if cur:
                chunks.append(cur)
                cur = ""
            chunks.append(b[:budget])
            b = b[budget:]
        if len(cur) + len(b) + 2 > budget:
            chunks.append(cur)
            cur = b
        else:
            cur = f"{cur}\n\n{b}" if cur else b
    if cur:
        chunks.append(cur)
    return chunks


# ---------------------------------------------------------------- claude

def _extract_json(text: str) -> dict | None:
    """Pull a JSON object out of a text reply (fallback when no tool call)."""
    m = re.search(r"```(?:json)?\s*(\{.*?\})\s*```", text, re.S)
    cand = m.group(1) if m else text[text.find("{"): text.rfind("}") + 1]
    try:
        obj = json.loads(cand)
        return obj if isinstance(obj, dict) and "candidates" in obj else None
    except (json.JSONDecodeError, ValueError):
        return None


# Some models reject forced tool_choice ("tool"/"any"); fall back to "auto".
_TOOL_CHOICE = {"type": "tool", "name": "report_candidates"}


def ask_claude(client, model, strings_text, decomp_chunk, idx, total, binary_name):
    global _TOOL_CHOICE
    kwargs = dict(
        model=model,
        max_tokens=16000,
        system=[
            {"type": "text", "text": SYSTEM_PROMPT},
            {
                # Same strings block on every chunk -> cache it.
                "type": "text",
                "text": f"<strings binary=\"{binary_name}\">\n{strings_text}\n</strings>",
                "cache_control": {"type": "ephemeral"},
            },
        ],
        tools=[TOOL],
        messages=[{
            "role": "user",
            "content": (
                f"Decompiler output chunk {idx}/{total} for {binary_name}:\n"
                f"<decomp>\n{decomp_chunk}\n</decomp>\n\n"
                "Identify component candidates using the strings and this chunk. "
                "Respond ONLY by calling the report_candidates tool."
            ),
        }],
    )
    try:
        resp = client.messages.create(tool_choice=_TOOL_CHOICE, **kwargs)
    except anthropic.BadRequestError as e:
        if "tool_choice" not in str(e) or _TOOL_CHOICE["type"] == "auto":
            raise
        print("[*] model rejects forced tool_choice; retrying with auto", file=sys.stderr)
        _TOOL_CHOICE = {"type": "auto"}
        resp = client.messages.create(tool_choice=_TOOL_CHOICE, **kwargs)

    for block in resp.content:
        if block.type == "tool_use" and block.name == "report_candidates":
            return block.input, resp.usage
    text = "".join(getattr(b, "text", "") for b in resp.content)
    parsed = _extract_json(text)
    if parsed is not None:
        return parsed, resp.usage
    return {"candidates": [], "notes": f"chunk {idx}: no tool output; reply was: {text[:500]}"}, resp.usage


def merge(results: list[dict]) -> tuple[list[dict], list[str]]:
    merged, notes = {}, []
    for r in results:
        if r.get("notes"):
            notes.append(r["notes"])
        for c in r.get("candidates", []) or []:
            if not isinstance(c, dict) or not c.get("name"):
                continue
            c.setdefault("version", "")
            c.setdefault("type", "library")
            c.setdefault("evidence", [])
            if c.get("confidence") not in CONF_RANK:
                c["confidence"] = "low"
            c["evidence"] = [e if isinstance(e, dict) else {"kind": "string", "value": str(e)}
                             for e in c["evidence"]]
            for e in c["evidence"]:
                e.setdefault("kind", "string"); e.setdefault("value", "")
            key = (c["name"].strip().lower(), (c.get("version") or "").strip().lower())
            if key not in merged:
                merged[key] = {**c, "evidence": list(c.get("evidence", []))}
                continue
            m = merged[key]
            if CONF_RANK[c["confidence"]] > CONF_RANK[m["confidence"]]:
                m["confidence"] = c["confidence"]
            for f in ("purl", "license", "version_notes"):
                if not m.get(f) and c.get(f):
                    m[f] = c[f]
            seen = {(e["kind"], e["value"]) for e in m["evidence"]}
            for e in c.get("evidence", []):
                if (e["kind"], e["value"]) not in seen:
                    m["evidence"].append(e)
                    seen.add((e["kind"], e["value"]))

    # If a name has both a versioned and unversioned entry, fold the
    # unversioned evidence into the versioned one.
    by_name = {}
    for (name, ver), c in merged.items():
        by_name.setdefault(name, []).append((ver, c))
    final = []
    for name, entries in by_name.items():
        versioned = [c for v, c in entries if v]
        unversioned = [c for v, c in entries if not v]
        if versioned and unversioned:
            target = max(versioned, key=lambda c: CONF_RANK[c["confidence"]])
            for u in unversioned:
                target["evidence"].extend(u["evidence"])
            final.extend(versioned)
        else:
            final.extend(c for _, c in entries)
    final.sort(key=lambda c: (-CONF_RANK[c["confidence"]], c["name"].lower()))
    return final, notes


def to_cyclonedx(binary: Path, candidates: list[dict]) -> dict:
    comps = []
    for c in candidates:
        comp = {
            "type": "library" if c["type"] in ("library", "runtime", "sdk") else
                    "framework" if c["type"] == "framework" else
                    "operating-system" if c["type"] == "rtos" else "library",
            "name": c["name"],
            "properties": [{"name": "sbom:confidence", "value": c["confidence"]}],
        }
        if c.get("version"):
            comp["version"] = c["version"]
        if c.get("purl"):
            comp["purl"] = c["purl"]
        if c.get("license"):
            comp["licenses"] = [{"license": {"id": c["license"]}}]
        comp["evidence"] = {
            "occurrences": [
                {"location": e.get("location") or e["value"],
                 "additionalContext": f'{e["kind"]}: {e["value"]}'}
                for e in c["evidence"]
            ]
        }
        comps.append(comp)
    return {
        "bomFormat": "CycloneDX",
        "specVersion": "1.6",
        "serialNumber": f"urn:uuid:{uuid.uuid4()}",
        "version": 1,
        "metadata": {
            "timestamp": datetime.now(timezone.utc).isoformat(),
            "component": {"type": "firmware", "name": binary.name},
            "tools": {"components": [{"type": "application", "name": "sbom_candidates.py"}]},
        },
        "components": comps,
    }


# ---------------------------------------------------------------- main

def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("binary", type=Path, help="Binary the strings are pulled from")
    ap.add_argument("--decomp", type=Path, default=Path("decomp.c"), help="Ghidra decompiler output (default: decomp.c)")
    ap.add_argument("--strings-script", type=Path, help="Your strings bash script (default: run strings -a -n 6)")
    ap.add_argument("--min-len", type=int, default=6, help="Min string length when not using a script")
    ap.add_argument("--model", default=os.environ.get("SBOM_MODEL", DEFAULT_MODEL))
    ap.add_argument("--strings-budget", type=int, default=120_000, help="Max chars of strings sent")
    ap.add_argument("--chunk-chars", type=int, default=250_000, help="Max chars of decomp per request")
    ap.add_argument("--max-chunks", type=int, default=20, help="Safety cap on API calls")
    ap.add_argument("--out", type=Path, default=Path("candidates.json"))
    ap.add_argument("--cyclonedx", type=Path, help="Also write a CycloneDX 1.6 SBOM here")
    ap.add_argument("--dry-run", action="store_true", help="Show what would be sent; no API calls")
    args = ap.parse_args()

    if not args.binary.is_file():
        sys.exit(f"Binary not found: {args.binary}")
    if not args.decomp.is_file():
        sys.exit(f"Decompiler output not found: {args.decomp} (run the Ghidra post-script first)")
    if not args.dry_run and not os.environ.get("ANTHROPIC_API_KEY"):
        sys.exit("Set ANTHROPIC_API_KEY first.")

    strings = get_strings(args.binary, args.strings_script, args.min_len)
    strings_text, dropped = fit_strings(strings, args.strings_budget)
    decomp = args.decomp.read_text(errors="replace")
    chunks = chunk_decomp(decomp, args.chunk_chars)

    print(f"[*] {len(strings)} unique strings ({dropped} trimmed to fit budget)", file=sys.stderr)
    print(f"[*] decomp.c: {len(decomp):,} chars -> {len(chunks)} chunk(s)", file=sys.stderr)
    if len(chunks) > args.max_chunks:
        sys.exit(f"{len(chunks)} chunks exceeds --max-chunks {args.max_chunks}; raise it or --chunk-chars.")
    if args.dry_run:
        print(strings_text[:2000], "\n...\n", chunks[0][:2000], file=sys.stderr)
        return

    client = anthropic.Anthropic(max_retries=4)
    results, errors = [], []
    totals = {"input": 0, "output": 0, "cache_read": 0}
    for i, chunk in enumerate(chunks, 1):
        print(f"[*] chunk {i}/{len(chunks)} -> {args.model}", file=sys.stderr)
        try:
            out, usage = ask_claude(client, args.model, strings_text, chunk, i, len(chunks), args.binary.name)
        except anthropic.AuthenticationError as e:
            sys.exit(f"[!] API key rejected (401). Check ANTHROPIC_API_KEY.\n    {e}")
        except anthropic.NotFoundError as e:
            sys.exit(f"[!] Model '{args.model}' not found (404). Try --model claude-opus-5-5.\n    {e}")
        except anthropic.PermissionDeniedError as e:
            sys.exit(f"[!] Permission denied (403) - key lacks access to this model/org.\n    {e}")
        except anthropic.BadRequestError as e:
            msg = str(e)
            hint = ("Out of API credits - add credits at console.anthropic.com > Billing."
                    if "credit" in msg.lower() else
                    "Request too large - lower --chunk-chars / --strings-budget."
                    if "too long" in msg.lower() or "too large" in msg.lower() or "context" in msg.lower() else
                    "Bad request.")
            sys.exit(f"[!] {hint}\n    {msg}")
        except (anthropic.APIError, Exception) as e:  # rate limit, overloaded, network
            print(f"[!] chunk {i} failed: {type(e).__name__}: {e}", file=sys.stderr)
            errors.append(f"chunk {i}: {type(e).__name__}: {e}")
            continue
        results.append(out)
        totals["input"] += usage.input_tokens
        totals["output"] += usage.output_tokens
        totals["cache_read"] += getattr(usage, "cache_read_input_tokens", 0) or 0

    if not results:
        sys.exit("[!] Every API call failed - no SBOM written.\n    " + "\n    ".join(errors))

    candidates, notes = merge(results)
    report = {
        "binary": str(args.binary.resolve()),
        "model": args.model,
        "generated": datetime.now(timezone.utc).isoformat(),
        "chunks": len(chunks),
        "strings_total": len(strings),
        "strings_trimmed": dropped,
        "usage": totals,
        "candidates": candidates,
        "notes": notes,
        "errors": errors,
    }
    args.out.write_text(json.dumps(report, indent=2))
    print(f"[+] {len(candidates)} candidate(s) -> {args.out}", file=sys.stderr)

    if args.cyclonedx:
        args.cyclonedx.write_text(json.dumps(to_cyclonedx(args.binary, candidates), indent=2))
        print(f"[+] CycloneDX SBOM -> {args.cyclonedx}", file=sys.stderr)

    for c in candidates:
        ver = c.get("version") or "?"
        print(f"  [{c['confidence']:<6}] {c['name']} {ver}  ({len(c['evidence'])} evidence)")
    print(f"[*] tokens: in={totals['input']:,} out={totals['output']:,} cache_read={totals['cache_read']:,}",
          file=sys.stderr)


if __name__ == "__main__":
    main()
