#!/bin/bash

# Ask for file name
read -p "Enter the filename: " file

# Check if file exists
if [ ! -f "$file" ]; then
    echo "File does not exist!"
    exit 1
fi

# Ask for the pattern to find
read -p "Enter the word/pattern to find: " find_word

# Ask for the replacement
read -p "Enter the word to replace it with: " replace_word

# Replace all occurrences using sed and save to a temporary file
sed "s/$find_word/$replace_word/g" "$file" > temp_file && mv temp_file "$file"

echo "All occurrences of '$find_word' have been replaced with '$replace_word' in '$file'."
