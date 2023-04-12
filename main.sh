#!/bin/sh

test_push_swap() {
    input=$1
    expected_output=$2

    output=$(./push_swap $input)
    echo "$output" > output.txt
    echo "$expected_output" > expected_output.txt
    if diff -q output.txt expected_output.txt > /dev/null; then
        echo "\033[32mTest passed: ./push_swap $input\033[0m\n"
    else
        echo "\033[31mTest failed: ./push_swap $input\033[0m\n"
        echo "Expected:"
        echo "$expected_output" | od -c
        echo "Got:"
        echo "$output" | od -c
    fi
}

echo "\n1 Number:\n"
test_push_swap "1" "Stack already correctly ordered"
echo "\n\n2 Numbers:\n"
test_push_swap "1 2" "Stack already correctly ordered"
echo "\n\nInt_max:\n"
test_push_swap "2147483647" "Stack already correctly ordered"
echo "\n\nInt_min:\n"
test_push_swap "-2147483648" "Stack already correctly ordered"
echo "\n\nNegative Numbers:\n"
test_push_swap "-5 2 10" "Stack already correctly ordered"
echo "\n\n3 Numbers:\n"
test_push_swap "2 1" "sa"
test_push_swap "2 1 3" "sa"
test_push_swap "3 2 1" "sa\nrra"
test_push_swap "3 1 2" "ra"
test_push_swap "1 3 2" "sa\nra"
test_push_swap "2 3 1" "rra"
test_push_swap "2 -5 -10" "sa\nrra"
echo "\n"
