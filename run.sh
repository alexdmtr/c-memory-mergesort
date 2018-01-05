#!/bin/bash
set -v
# Generate 1,000,000 ints
python3 src/int_generator.py > ints.txt

# Compile the c code.
g++ src/main.c > a.out

# Run the code.
time ./a.out < ints.txt > sorted.txt

rm a.out
