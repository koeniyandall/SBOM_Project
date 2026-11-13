How to Run

1. Clone the repository
2. Set claude API in enviroment variables ( > export ANTHROPIC_API_KEY=...)
3. Go to tools/
4. run ./run_sbom.sh [binary file] ... [more binary files] (will most likely prompt you to download some dependencies)


How it Works

1. Run "> strings -n 6 <firmware.bin>"
2. Run headless ghidra decompiler
3. Feed these outputs to claude API
4. Claude returns "candidates" based on the strings and headless ghidra output with certainty scores and evidence

Next Steps
1. Find a way to bindiff decomp.c with a compiled version of that open source software and version (use the candidates.verified.json)

After these steps, we should have a real, verified candidates list alongside confidence scores
