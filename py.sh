#!/bin/sh

code_file=${1:-"a"}
input_file=${2:-"test.in"}
output_file=${3:-"test.out"}

python3 _work/py/$code_file.py < $input_file > $output_file
