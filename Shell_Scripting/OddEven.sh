#!/bin/bash

# Ask the user to enter a number
read -p "Enter a number: " num

# Check if the number is divisible by 2
if [ $((num % 2)) -eq 0 ]; then
    echo "$num is Even"
else
    echo "$num is Odd"
fi