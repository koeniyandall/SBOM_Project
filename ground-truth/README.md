# Ground-truth firmware for the SBOM project

Fake ECU firmware where **we already know what's inside**, so we can
measure whether our SBOM tool gets the right answer.

## Setup (Ubuntu / WSL)

    sudo apt install gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi git
    mkdir deps && cd deps
    git clone --depth 1 --branch v1.2.13 https://github.com/madler/zlib.git zlib-v1.2.13
    git clone --depth 1 --branch v1.3.1  https://github.com/madler/zlib.git zlib-v1.3.1
    cd .. && ./build.sh

## What you get (out/<version>/)

| File | What it is | Use it for |
|---|---|---|
| firmware.bin | Raw flash image, no headers, no symbols | **Analyze this.** Closest to a real ECU dump |
| firmware_stripped.elf | ELF with names removed | Easier practice target |
| firmware.elf | Full symbols | Answer key: open it to see the real function names |
| ground_truth.json | Components + versions inside | Grade your SBOM against this |

## Exercises, in order

1. **Strings.** `strings -n 6 out/v1.3.1/firmware.bin | grep -E '[0-9]+\.[0-9]+\.[0-9]+'`
   finds the zlib version. Notice zlib's copyright banner did NOT survive
   (the linker removed it as unused). Real firmware loses strings the same
   way, so strings alone isn't reliable.
2. **Constants.** zlib's CRC-32 table starts with bytes `96 30 07 77`.
   Search for it in a hex editor. Constants survive even when strings don't,
   but they tell you "zlib", not which version.
3. **Ghidra.** File > Import `firmware.bin`, Language `ARM:LE:32:Cortex`,
   Options > Base Address `0x08000000`. Run auto-analysis. Address 0x08000004
   holds the reset handler pointer; follow it to find main().
4. **Function matching.** Open `firmware.elf` in Ghidra too, and compare
   functions with the stripped one. This is what Function ID / BSim / BinDiff
   automate: recognizing library functions by their code instead of names.
5. **Versions.** Diff the v1.2.13 and v1.3.1 images. Same size, different
   bytes. Finding *which* functions changed is how you tell versions apart
   when there's no version string.

## Growing the dataset

Add more libraries (mbedTLS, FreeRTOS, lwIP), more versions, and other
optimization levels (`-O0`, `-O2`) in build.sh. Each new image + its
ground_truth.json is another test case for the tool.
