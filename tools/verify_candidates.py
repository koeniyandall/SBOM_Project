#!/usr/bin/env python3

import subprocess
import json
import sys, os

out_dir = sys.argv[1]
candidates_path = os.path.join(out_dir, "candidates.json")
strings_path = os.path.join(out_dir, "strings.txt")
decomp_path = os.path.join(out_dir, "decomp.c")

with open(candidates_path, "r", encoding="utf-8") as file:
    data = json.load(file)

def check_exists(check: str, kind: str) -> bool:
    if kind == "string":
        result = subprocess.run(["grep", "-i", "-F", "--",check, strings_path], capture_output=True, text=True)
    else:
        result = subprocess.run(["grep", "-i", "-F","--",check, decomp_path], capture_output=True, text=True)
    found = result.returncode
    return not found

def main():
    kept_candidates = []
    rejected = []
    for candidate in data["candidates"]:
        kept = []
        for artifact in candidate["evidence"]:
            if check_exists(artifact["value"], artifact["kind"]):
                kept.append(artifact)
        candidate["evidence"] = kept

        if kept:
            kept_candidates.append(candidate)
        else:
            rejected.append(candidate["name"])

    data["candidates"] = kept_candidates
    data["rejected"] = rejected
    with open("/Users/keoniyandall/SBOM_Project/sbom-out/firmware/candidates.filtered.json", "w", encoding="utf-8") as f:
        json.dump(data, f, indent=2)

if __name__ == "__main__":
    main()