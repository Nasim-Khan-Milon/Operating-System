#!/bin/bash

# Ask user for filename
read -p "Enter the filename: " file

# Check if file exists
if [ ! -f "$file" ]; then
    echo "File does not exist!"
    exit 1
fi

# Count words using wc command
word_count=$(wc -w < "$file")

echo "The file '$file' has $word_count words."
