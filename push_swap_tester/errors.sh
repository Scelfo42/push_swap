#!/bin/sh

check_errors() {
    input=$1
    expected_output=$2
    mkdir -p outputs
    rm -f outputs/*

    output=$(./../../42cursus/push_swap/push_swap $input 2>&1)
    echo "$input" > outputs/errors_input.txt
    echo "$output" > outputs/errors_output.txt
    echo "$expected_output" > outputs/errors_expected_output.txt
    if diff -q outputs/errors_output.txt outputs/errors_expected_output.txt > /dev/null; then
        echo "\033[32mTest passed: ./push_swap $input\033[0m\n"
    else
        echo "\033[31mTest failed: ./push_swap $input\033[0m\n"
        echo "Expected:"
        echo "$expected_output" | od -c
        echo "Got:"
        echo "$output" | od -c
    fi
}

check_errors_split() {
    input=$1
    expected_output=$2
    mkdir -p outputs
    rm -f outputs/*

    output=$(./../../42cursus/push_swap/push_swap "$input" 2>&1)
    echo "$input" > outputs/errors_input.txt
    echo "$output" > outputs/errors_output.txt
    echo "$expected_output" > outputs/errors_expected_output.txt
    if diff -q outputs/errors_output.txt outputs/errors_expected_output.txt > /dev/null; then
        echo "\033[32mTest passed: ./push_swap "$input"\033[0m\n"
    else
        echo "\033[31mTest failed: ./push_swap "$input"\033[0m\n"
        echo "Expected:"
        echo "$expected_output" | od -c
        echo "Got:"
        echo "$output" | od -c
    fi
}

echo "\nDuplicates found"
check_errors "1 2 1" "Error"
echo "Letters inside args:"
check_errors "0 one 2 3" "Error"
echo "Letter near args:"
check_errors "0 1 2a 3" "Error"
echo "int max overflow:"
check_errors "2147483648" "Error"
echo "int min underflow:"
check_errors "-2147483649" "Error"
echo "\nWith Split:"
echo "\nDuplicates found"
check_errors_split "1 2 1" "Error"
echo "Letters inside args:"
check_errors_split "0 one 2 3" "Error"
echo "Letter near args:"
check_errors_split "0 1 2a 3" "Error"
echo "int max overflow:"
check_errors_split "2147483648" "Error"
echo "int min underflow:"
check_errors_split "-2147483649" "Error"
echo "\n"