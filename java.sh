#!/usr/bin/env sh

code_file=${1:-"a"}
input_file=${2:-"test.in"}

java _work/java/$code_file.java < $input_file > test.out
