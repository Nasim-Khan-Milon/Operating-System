#!/bin/bash

# Ask user for source file/directory
read -p "Enter the file or directory to backup: " src

# Check if source exists
if [ ! -e "$src" ]; then
    echo "Source does not exist!"
    exit 1
fi

# Ask user for backup destination
read -p "Enter backup destination path: " dest

# Create backup
if [ -d "$src" ]; then
    # If source is a directory, copy recursively
    cp -r "$src" "$dest"
elif [ -f "$src" ]; then
    # If source is a file, copy normally
    cp "$src" "$dest"
fi

echo "Backup completed from '$src' to '$dest'."
