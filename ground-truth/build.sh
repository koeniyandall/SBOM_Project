#!/usr/bin/env bash
# Builds fake ECU firmware images with a KNOWN library + version inside,
# so you can test whether your SBOM tool identifies them correctly.
#
# For each zlib version it produces, in out/<version>/:
#   firmware.elf           full symbols  -> the "answer key" binary
#   firmware_stripped.elf  no symbols    -> what you analyze
#   firmware.bin           raw flash dump-> closest to a real ECU dump
#   ground_truth.json      the SBOM you SHOULD recover
set -euo pipefail
cd "$(dirname "$0")"

CC=arm-none-eabi-gcc
CFLAGS="-mcpu=cortex-m4 -mthumb -Os -ffunction-sections -fdata-sections"
ZLIB_SRC="adler32.c compress.c crc32.c deflate.c inflate.c inffast.c inftrees.c trees.c uncompr.c zutil.c"

for v in v1.2.13 v1.3.1; do
  zdir="deps/zlib-$v"
  out="out/$v"
  mkdir -p "$out"
  objs=()

  # Compile each zlib source file for the ARM chip
  for f in $ZLIB_SRC; do
    o="$out/${f%.c}.o"
    $CC $CFLAGS -DZ_SOLO=0 -I"$zdir" -c "$zdir/$f" -o "$o"
    objs+=("$o")
  done

  # Compile our firmware and link everything into one image
  $CC $CFLAGS -I"$zdir" -c src/main.c -o "$out/main.o"
  $CC $CFLAGS -T src/cortex_m4.ld -nostartfiles \
      --specs=nano.specs --specs=nosys.specs -Wl,--gc-sections \
      "$out/main.o" "${objs[@]}" -o "$out/firmware.elf"

  # Make the "realistic" versions: stripped ELF and raw binary
  arm-none-eabi-strip -o "$out/firmware_stripped.elf" "$out/firmware.elf"
  arm-none-eabi-objcopy -O binary "$out/firmware.elf" "$out/firmware.bin"
  rm -f "$out"/*.o

  # Write the answer key
  cat > "$out/ground_truth.json" <<EOF
{
  "firmware": "out/$v/firmware.bin",
  "architecture": "ARM Cortex-M4 (Thumb-2), little-endian",
  "flash_base_address": "0x08000000",
  "components": [
    {"name": "zlib",   "version": "${v#v}", "source": "https://github.com/madler/zlib"},
    {"name": "newlib-nano", "version": "from $( $CC --version | head -1 )", "note": "C library (memcmp, memcpy)"}
  ]
}
EOF
  echo "built $out ($(stat -c %s "$out/firmware.bin") bytes raw)"
done
