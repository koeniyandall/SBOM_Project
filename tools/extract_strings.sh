#!/bin/bash

# 1. Check if a file argument was provided
if [ -z "$1" ]; then
    echo "Error: No file provided." >&2
    echo "Usage: $0 <path_to_file>" >&2
    exit 1
fi

FILE_PATH="$1"

# 2. Check if the target file actually exists
if [ ! -f "$FILE_PATH" ]; then
    echo "Error: File '$FILE_PATH' does not exist or is not a regular file." >&2
    exit 1
fi

# 3. Run the strings command on the file
echo "=== Extracting printable strings from: $FILE_PATH ==="
strings -a -n 6 "$FILE_PATH"
