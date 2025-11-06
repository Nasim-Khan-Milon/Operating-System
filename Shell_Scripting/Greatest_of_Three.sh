#!/bin/bash

# Take three numbers as input
read -p "Enter first number: " a
read -p "Enter second number: " b
read -p "Enter third number: " c

# Compare numbers to find the greatest
if [ $a -ge $b ] && [ $a -ge $c ]; then
    echo "Greatest number is $a"
elif [ $b -ge $a ] && [ $b -ge $c ]; then
    echo "Greatest number is $b"
else
    echo "Greatest number is $c"
fi
