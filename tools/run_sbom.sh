#!/usr/bin/env bash
# run_sbom.sh - One command: binary in, SBOM candidates out.
#
#   1. Imports + analyzes the binary in Ghidra headless (pyghidraRun)
#   2. Runs your export_code.py post-script to produce decomp.c
#   3. Runs your strings script on the binary
#   4. Sends strings + decomp.c to the Claude API via sbom_candidates.py
#
# Usage:
#   ./run_sbom.sh <binary> [more binaries...]
#
# Output (per binary): $OUT_ROOT/<binary-name>/
#   decomp.c  strings.txt  candidates.json  sbom.cdx.json  ghidra.log
#
# Raw firmware (.bin with no ELF header) is detected automatically and
# loaded with BinaryLoader using RAW_PROCESSOR / RAW_BASE_ADDR below.

set -euo pipefail

# ---------------------------------------------------------------- config
# Override any of these with environment variables.
GHIDRA_HOME="${GHIDRA_HOME:-/Users/keoniyandall/Downloads/ghidra_12.2_PUBLIC}"
PROJECT_DIR="${PROJECT_DIR:-/Users/keoniyandall/Senior_Project}"
PROJECT_NAME="${PROJECT_NAME:-Ghidra_folder}"
POST_SCRIPT="${POST_SCRIPT:-$GHIDRA_HOME/support/export_code.py}"

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
STRINGS_SCRIPT="${STRINGS_SCRIPT:-$SCRIPT_DIR/extract_strings.sh}"
SBOM_PY="${SBOM_PY:-$SCRIPT_DIR/sbom_candidates.py}"
OUT_ROOT="${OUT_ROOT:-$PROJECT_DIR/sbom-out}"
# Use the venv next to this script if present (Homebrew blocks global pip installs).
if [[ -x "$SCRIPT_DIR/.venv/bin/python3" ]]; then
    PYTHON="${PYTHON:-$SCRIPT_DIR/.venv/bin/python3}"
else
    PYTHON="${PYTHON:-python3}"
fi

SBOM_MODEL="${SBOM_MODEL:-claude-sonnet-5-5}"
RAW_PROCESSOR="${RAW_PROCESSOR:-ARM:LE:32:Cortex}"
RAW_BASE_ADDR="${RAW_BASE_ADDR:-0x08000000}"
SKIP_GHIDRA="${SKIP_GHIDRA:-0}"   # 1 = reuse existing decomp.c in the output dir

# ---------------------------------------------------------------- helpers
log()  { printf '\033[1;34m[*]\033[0m %s\n' "$*" >&2; }
ok()   { printf '\033[1;32m[+]\033[0m %s\n' "$*" >&2; }
die()  { printf '\033[1;31m[!]\033[0m %s\n' "$*" >&2; exit 1; }

abspath() { (cd "$(dirname "$1")" && printf '%s/%s\n' "$(pwd)" "$(basename "$1")"); }

preflight() {
    [[ $# -ge 1 ]] || die "Usage: $0 <binary> [more binaries...]"
    [[ -x "$GHIDRA_HOME/support/pyghidraRun" ]] || die "pyghidraRun not found under GHIDRA_HOME=$GHIDRA_HOME"
    [[ -f "$POST_SCRIPT" ]]   || die "Post-script not found: $POST_SCRIPT"
    [[ -f "$SBOM_PY" ]]       || die "sbom_candidates.py not found: $SBOM_PY"
    [[ -n "${ANTHROPIC_API_KEY:-}" ]] || die "Set ANTHROPIC_API_KEY first (e.g. in ~/.zshrc)."
    command -v "$PYTHON" >/dev/null || die "python not found: $PYTHON"
    "$PYTHON" -c 'import anthropic' 2>/dev/null || die "anthropic missing. Run: python3 -m venv \"$SCRIPT_DIR/.venv\" && \"$SCRIPT_DIR/.venv/bin/pip\" install anthropic"
    if [[ ! -f "$STRINGS_SCRIPT" ]]; then
        log "Strings script not at $STRINGS_SCRIPT - falling back to 'strings -a -n 6'"
        STRINGS_SCRIPT=""
    fi
    if [[ -z "$(find "$GHIDRA_HOME/Ghidra/Features/Decompiler" -type f -name decompile -perm -u+x 2>/dev/null | head -n1)" ]]; then
        log "Warning: decompiler native binary missing - run 'gradle buildNatives' in $GHIDRA_HOME/support/gradle"
    fi
    mkdir -p "$PROJECT_DIR" "$OUT_ROOT"
}

# Raw images need an explicit loader + processor; ELF/PE/Mach-O don't.
loader_args() {
    local bin="$1" desc
    desc="$(file -b "$bin")"
    case "$desc" in
        ELF*|PE32*|Mach-O*|MS-DOS*) ;;
        *)
            log "No recognized header ($desc) - loading raw as $RAW_PROCESSOR @ $RAW_BASE_ADDR"
            printf '%s\n' -loader BinaryLoader -processor "$RAW_PROCESSOR" -loader-baseAddr "$RAW_BASE_ADDR"
            ;;
    esac
}

run_ghidra() {
    local bin="$1" out="$2"
    local -a extra=()
    while IFS= read -r a; do [[ -n "$a" ]] && extra+=("$a"); done < <(loader_args "$bin")

    rm -f "$out/decomp.c"
    log "Ghidra: importing + analyzing $(basename "$bin") (log: $out/ghidra.log)"
    # Run from the output dir so a post-script that writes to the CWD lands here.
    (
        cd "$out"
        "$GHIDRA_HOME/support/pyghidraRun" --headless \
            "$PROJECT_DIR" "$PROJECT_NAME" \
            -import "$bin" -overwrite \
            ${extra[@]+"${extra[@]}"} \
            -postScript "$POST_SCRIPT" "$out/decomp.c"
    ) >"$out/ghidra.log" 2>&1 || {
        tail -n 30 "$out/ghidra.log" >&2
        die "Ghidra failed for $bin (full log: $out/ghidra.log)"
    }
    grep -q "Import succeeded\|Analysis succeeded" "$out/ghidra.log" || {
        tail -n 30 "$out/ghidra.log" >&2
        die "Ghidra did not report success for $bin"
    }

    # If export_code.py ignores the path argument, find where it put decomp.c.
    if [[ ! -s "$out/decomp.c" ]]; then
        local found
        found="$(find "$out" "$GHIDRA_HOME/support" "$PROJECT_DIR" -maxdepth 2 -name decomp.c -newer "$out/ghidra.log" -print -quit 2>/dev/null || true)"
        [[ -z "$found" ]] && found="$(find "$out" "$GHIDRA_HOME/support" "$PROJECT_DIR" -maxdepth 2 -name decomp.c -mmin -10 -print -quit 2>/dev/null || true)"
        [[ -n "$found" && -s "$found" ]] || die "decomp.c was not produced - check $out/ghidra.log"
        [[ "$found" != "$out/decomp.c" ]] && mv "$found" "$out/decomp.c"
    fi
    ok "decomp.c: $(wc -l <"$out/decomp.c" | tr -d ' ') lines"
}

process_one() {
    local bin name out
    bin="$(abspath "$1")"
    [[ -f "$bin" ]] || die "Not a file: $1"
    name="$(basename "$bin")"
    out="$OUT_ROOT/${name%.*}"
    mkdir -p "$out"

    log "=== $name -> $out ==="

    if [[ "$SKIP_GHIDRA" == "1" && -s "$out/decomp.c" ]]; then
        log "SKIP_GHIDRA=1: reusing $out/decomp.c"
    else
        run_ghidra "$bin" "$out"
    fi

    # Keep a copy of the strings for your records / ground-truth diffing.
    if [[ -n "$STRINGS_SCRIPT" ]]; then
        bash "$STRINGS_SCRIPT" "$bin" >"$out/strings.txt"
    else
        strings -a -n 6 "$bin" >"$out/strings.txt"
    fi
    ok "strings: $(wc -l <"$out/strings.txt" | tr -d ' ') lines"

    log "Claude ($SBOM_MODEL): identifying components"
    local -a sargs=()
    [[ -n "$STRINGS_SCRIPT" ]] && sargs=(--strings-script "$STRINGS_SCRIPT")
    "$PYTHON" "$SBOM_PY" "$bin" \
        --decomp "$out/decomp.c" \
        ${sargs[@]+"${sargs[@]}"} \
        --model "$SBOM_MODEL" \
        --out "$out/candidates.json" \
        --cyclonedx "$out/sbom.cdx.json"

    ok "Done: $out/candidates.json, $out/sbom.cdx.json"
}

# ---------------------------------------------------------------- main
preflight "$@"
fail=0
for b in "$@"; do
    ( process_one "$b" ) || { fail=$((fail + 1)); log "Continuing after failure on $b"; }
done
[[ $fail -eq 0 ]] && ok "All $# binaries processed." || die "$fail of $# binaries failed."
