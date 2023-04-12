#!/bin/sh

check_memory_leaks() {
    input=$1

    valgrind_output=$(valgrind --leak-check=full ./push_swap $input 2>&1)
    if echo "$valgrind_output" | grep -q "All heap blocks were freed -- no leaks are possible"; then
        echo "\033[32mNo memory leaks: ./push_swap $input\033[0m\n"
    else
        echo "\033[31mMemory leaks detected: ./push_swap $input\033[0m\n"
        echo "$valgrind_output"
    fi
}

check_memory_leaks ""
check_memory_leaks " "
check_memory_leaks "0 one 2 3"
check_memory_leaks "0 1 2a 3"
check_memory_leaks "2147483648"
check_memory_leaks "-2147483649"
check_memory_leaks "2147483647"
check_memory_leaks "1"
check_memory_leaks "1 2"
check_memory_leaks "-2147483648"
check_memory_leaks "-5 2 10"
check_memory_leaks "2 1"
check_memory_leaks "2 1 3"
check_memory_leaks "3 2 1"
check_memory_leaks "3 1 2"
check_memory_leaks "1 3 2"
check_memory_leaks "2 3 1"
check_memory_leaks "2 -5 -10"
