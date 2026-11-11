#!/usr/bin/env bash
# build_matrix.sh - Build many ground-truth firmware images:
#   every LIBRARY x VERSION x CPU x OPTIMIZATION LEVEL.
#
# Output: out/<lib>-<version>/<cpu>-<opt>/
#   firmware.elf           full symbols  -> answer key
#   firmware_stripped.elf  no symbols    -> practice target
#   firmware.bin           raw flash dump-> realistic target
#   ground_truth.json      what your SBOM tool SHOULD find
#
# Works on macOS (bash 3.2) and Linux. Library sources are cloned into
# deps/ automatically the first time.
#
# Usage:
#   ./build_matrix.sh                     # everything
#   LIBS="cjson" ./build_matrix.sh        # one library
#   CPUS="cortex-m0 cortex-m7" OPTS="-O0 -Os" ./build_matrix.sh
set -euo pipefail
cd "$(dirname "$0")"

CC=arm-none-eabi-gcc
LIBS="${LIBS:-zlib cjson littlefs}"
CPUS="${CPUS:-cortex-m0 cortex-m3 cortex-m4 cortex-m7 cortex-m33}"
OPTS="${OPTS:--O0 -Os -O2}"

command -v "$CC" >/dev/null || {
    echo "arm-none-eabi-gcc not found." >&2
    echo "  macOS: brew install --cask gcc-arm-embedded" >&2
    echo "  Linux: sudo apt install gcc-arm-none-eabi libnewlib-arm-none-eabi" >&2
    exit 1
}

# ------------------------------------------------------------ per-library info
versions_for() {
    case "$1" in
        zlib)     echo "v1.2.13 v1.3.1" ;;
        cjson)    echo "v1.7.15 v1.7.18" ;;
        littlefs) echo "v2.8.0 v2.9.3" ;;
        *) echo "Unknown library: $1" >&2; exit 1 ;;
    esac
}
repo_for() {
    case "$1" in
        zlib)     echo "https://github.com/madler/zlib.git" ;;
        cjson)    echo "https://github.com/DaveGamble/cJSON.git" ;;
        littlefs) echo "https://github.com/littlefs-project/littlefs.git" ;;
    esac
}
sources_for() {   # library .c files, relative to deps/<lib>-<version>/
    case "$1" in
        zlib)     echo "adler32.c compress.c crc32.c deflate.c inflate.c inffast.c inftrees.c trees.c uncompr.c zutil.c" ;;
        cjson)    echo "cJSON.c" ;;
        littlefs) echo "lfs.c lfs_util.c" ;;
    esac
}
defines_for() {   # keep littlefs from pulling in printf
    case "$1" in
        littlefs) echo "-DLFS_NO_DEBUG -DLFS_NO_WARN -DLFS_NO_ERROR -DLFS_NO_ASSERT" ;;
        *)        echo "" ;;
    esac
}
display_name() {
    case "$1" in
        zlib) echo "zlib" ;; cjson) echo "cJSON" ;; littlefs) echo "littlefs" ;;
    esac
}
arch_for() {
    case "$1" in
        cortex-m0)  echo "ARMv6-M (Thumb)" ;;
        cortex-m3)  echo "ARMv7-M (Thumb-2)" ;;
        cortex-m4)  echo "ARMv7E-M (Thumb-2, DSP)" ;;
        cortex-m7)  echo "ARMv7E-M (Thumb-2, DSP)" ;;
        cortex-m33) echo "ARMv8-M Mainline (Thumb-2)" ;;
        *)          echo "unknown" ;;
    esac
}

# ------------------------------------------------------------ build
toolchain="$($CC --version | head -1)"
built=0; failed=0
mkdir -p deps out

for lib in $LIBS; do
    for ver in $(versions_for "$lib"); do
        src_dir="deps/$lib-$ver"
        if [ ! -d "$src_dir" ]; then
            echo "[*] Cloning $lib $ver"
            git clone -q --depth 1 --branch "$ver" "$(repo_for "$lib")" "$src_dir"
        fi

        for cpu in $CPUS; do
            for opt in $OPTS; do
                out="out/$lib-$ver/$cpu${opt}"
                mkdir -p "$out"
                cflags="-mcpu=$cpu -mthumb $opt -ffunction-sections -fdata-sections $(defines_for "$lib")"
                objs=""

                if ! (
                    for f in $(sources_for "$lib"); do
                        o="$out/$(basename "${f%.c}").o"
                        $CC $cflags -I"$src_dir" -c "$src_dir/$f" -o "$o"
                    done
                    $CC $cflags -I"$src_dir" -c "src/app_$lib.c" -o "$out/app.o"
                    $CC $cflags -c src/startup.c -o "$out/startup.o"
                    $CC $cflags -T src/cortex_m4.ld -nostartfiles \
                        --specs=nano.specs --specs=nosys.specs -Wl,--gc-sections \
                        "$out"/*.o -o "$out/firmware.elf"
                    arm-none-eabi-strip -o "$out/firmware_stripped.elf" "$out/firmware.elf"
                    arm-none-eabi-objcopy -O binary "$out/firmware.elf" "$out/firmware.bin"
                ) 2>"$out/build.log"; then
                    echo "[!] FAILED $lib $ver $cpu $opt (see $out/build.log)"
                    failed=$((failed + 1))
                    continue
                fi
                rm -f "$out"/*.o "$out/build.log"

                cat > "$out/ground_truth.json" <<EOF
{
  "firmware": "$out/firmware.bin",
  "cpu": "$cpu",
  "architecture": "$(arch_for "$cpu"), little-endian",
  "optimization": "$opt",
  "flash_base_address": "0x08000000",
  "ghidra_language": "ARM:LE:32:Cortex",
  "components": [
    {"name": "$(display_name "$lib")", "version": "${ver#v}", "source": "$(repo_for "$lib" | sed 's/\.git$//')"},
    {"name": "newlib-nano", "version": "from $toolchain", "note": "C library (memcpy, memset, etc.)"}
  ]
}
EOF
                size=$(wc -c < "$out/firmware.bin" | tr -d ' ')
                echo "[+] $lib $ver  $cpu $opt  ${size} bytes"
                built=$((built + 1))
            done
        done
    done
done

echo
echo "Built $built images, $failed failed."
[ "$failed" -eq 0 ]
