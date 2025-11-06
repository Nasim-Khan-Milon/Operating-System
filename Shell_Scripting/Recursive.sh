#!/bin/bash

# Ask user for directory
read -p "Enter directory to list files recursively: " dir

# Check if directory exists
if [ ! -d "$dir" ]; then
    echo "Directory does not exist!"
    exit 1
fi

echo "Listing all files in '$dir' recursively:"

# Use find command to list files recursively
find "$dir" -type f
