#!/bin/sh

code_file=${1:-"a"}
input_file=${2:-"test.in"}
output_file=${3:-"test.out"}

make x=$code_file
./a.out < $input_file > $output_file
