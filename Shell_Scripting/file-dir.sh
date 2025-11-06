#!/bin/bash

# Ask user for a file/directory name
read -p "Enter file or directory name: " name

# Check if it exists
if [ -e "$name" ]; then
    echo "$name exists."
    
    # Check if it is a regular file
    if [ -f "$name" ]; then
        echo "$name is a file."
    fi

    # Check if it is a directory
    if [ -d "$name" ]; then
        echo "$name is a directory."
    fi
else
    echo "$name does not exist."
fi

# Count total files and directories in current directory
file_count=$(ls -l | grep ^- | wc -l)
dir_count=$(ls -l | grep ^d | wc -l)

echo "Total files in current directory: $file_count"
echo "Total directories in current directory: $dir_count"
