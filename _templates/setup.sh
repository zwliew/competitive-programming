#!/bin/sh

# Run this script from the root project directory

# Setup working directories
mkdir -p _work/cpp
mkdir -p _work/py

# Set up C++ working directory
cp _templates/template.cc _work/cpp/a.cc
cp _templates/template.cc _work/cpp/b.cc
cp _templates/template.cc _work/cpp/c.cc
cp _templates/template.cc _work/cpp/d.cc
cp _templates/template.cc _work/cpp/e.cc
cp _templates/template.cc _work/cpp/f.cc

# Set up Python working directory
cp _templates/template.py _work/py/a.py
cp _templates/template.py _work/py/b.py
cp _templates/template.py _work/py/c.py
cp _templates/template.py _work/py/d.py
cp _templates/template.py _work/py/e.py
cp _templates/template.py _work/py/f.py

# Set up test I/O files
touch test.in
touch test.out
