#!/bin/sh

code_file=${1:-"a"}
input_file=${2:-"test.in"}

make x=$code_file
./a.out < $input_file > test.out
