#!/bin/sh

check_memory_leaks() {
    input=$1
    mkdir -p outputs
    rm -f outputs/*

    valgrind_output=$(valgrind --leak-check=full ./../../42cursus/push_swap/push_swap $input 2>&1)
    echo "$input" > outputs/memory_input.txt
    echo "$output" > outputs/memory_output.txt
    echo "$expected_output" > outputs/memory_expected_output.txt
    if echo "$valgrind_output" | grep -q "All heap blocks were freed -- no leaks are possible"; then
        echo "\033[32mNo memory leaks: ./push_swap $input\033[0m\n"
    else
        echo "\033[31mMemory leaks detected: ./push_swap $input\033[0m\n"
        echo "$valgrind_output"
    fi
}

check_memory_leaks_split() {
    input=$1
    mkdir -p outputs

    valgrind_output=$(valgrind --leak-check=full ./../../42cursus/push_swap/push_swap "$input" 2>&1)
    echo "$input" > outputs/memory_input.txt
    echo "$output" > outputs/memory_output.txt
    echo "$expected_output" > outputs/memory_expected_output.txt
    if echo "$valgrind_output" | grep -q "All heap blocks were freed -- no leaks are possible"; then
        echo "\033[32mNo memory leaks: ./push_swap "$input"\033[0m\n"
    else
        echo "\033[31mMemory leaks detected: ./push_swap "$input"\033[0m\n"
        echo "$valgrind_output"
    fi
}

echo "\nMemory with errors occured:"
check_memory_leaks "0 2 2 3"
check_memory_leaks "0 one 2 3"
check_memory_leaks "0 1 2a 3"
check_memory_leaks "2147483648"
check_memory_leaks "-2147483649"
echo "\nMemory with Max and Min INT:"
check_memory_leaks "2147483647"
check_memory_leaks "-2147483648"
echo "\nMemory with numbers already ordered:"
check_memory_leaks "1"
check_memory_leaks "1 2"
check_memory_leaks "1 2 3"
check_memory_leaks "1 2 3 4 5"
echo "\nMemory with Positive and negative numbers:"
check_memory_leaks "-5 2 10"
check_memory_leaks "2 1"
check_memory_leaks "2 1 3"
check_memory_leaks "3 2 1"
check_memory_leaks "3 1 2"
check_memory_leaks "1 3 2"
check_memory_leaks "2 3 1"
check_memory_leaks "2 -5 -10"
echo "\nMemory with "input" like a single argument:\n"
echo "Edge cases:"
check_memory_leaks_split ""
check_memory_leaks_split " "
echo "Memory with errors occured:"
check_memory_leaks_split "0 2 2 3"
check_memory_leaks_split "0 one 2 3"
check_memory_leaks_split "0 1 2a 3"
check_memory_leaks_split "2147483648"
check_memory_leaks_split "-2147483649"
echo "\nMemory with random numbers:"
check_memory_leaks_split "1"
check_memory_leaks_split "1 2"
check_memory_leaks_split "-5 2 10"
check_memory_leaks_split "2 1"
check_memory_leaks_split "2 1 3"
check_memory_leaks_split "3 2 1"
check_memory_leaks_split "3 1 2"
check_memory_leaks_split "1 3 2"
check_memory_leaks_split "2 3 1"
check_memory_leaks_split "2 -5 -10"