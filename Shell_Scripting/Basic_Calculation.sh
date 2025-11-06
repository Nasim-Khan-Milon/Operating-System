#!/bin/bash

echo "Basic Calculator"
echo "Enter first number: "
read num1
echo "Enter second number: "
read num2

echo "Select operation: + - * /"
read op

case $op in
    +)
        result=$((num1 + num2))
        ;;
    -)
        result=$((num1 - num2))
        ;;
    \*)  # Escape * because it's a special character in shell
        result=$((num1 * num2))
        ;;
    /)
        if [ $num2 -ne 0 ]; then
            result=$((num1 / num2))
        else
            echo "Error: Division by zero!"
            exit 1
        fi
        ;;
    *)
        echo "Invalid operator!"
        exit 1
        ;;
esac

echo "Result: $num1 $op $num2 = $result"
