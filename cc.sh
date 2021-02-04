#!/bin/sh

file=${1:-"a"}

make x=$file
./a.out < test.in > test.out
