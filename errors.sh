#!/bin/sh

check_errors() {
    input=$1
    expected_output=$2

    output=$(./push_swap $input 2>&1)
    echo "$input" > errors_input.txt
    echo "$output" > errors_output.txt
    echo "$expected_output" > errors_expected_output.txt
    if diff -q errors_output.txt errors_expected_output.txt > /dev/null; then
        echo "\033[32mTest passed: ./push_swap $input\033[0m\n"
    else
        echo "\033[31mTest failed: ./push_swap $input\033[0m\n"
        echo "Expected:"
        echo "$expected_output" | od -c
        echo "Got:"
        echo "$output" | od -c
    fi
}

echo "\nLetters inside args:"
check_errors "0 one 2 3" "Error"
echo "Letter near args:"
check_errors "0 1 2a 3" "Error"
echo "int max overflow:"
check_errors "2147483648" "Error"
echo "int min underflow:"
check_errors "-2147483649" "Error"
echo "\n"
