#!/bin/sh

# Run this script from the root project directory

# Set up C++ working directory
mkdir -p _work/cc
cp _templates/template.cc _work/cc/a.cc
cp _templates/template.cc _work/cc/b.cc
cp _templates/template.cc _work/cc/c.cc
cp _templates/template.cc _work/cc/d.cc
cp _templates/template.cc _work/cc/e.cc
cp _templates/template.cc _work/cc/f.cc

# Set up Python working directory
mkdir -p _work/py
cp _templates/template.py _work/py/a.py
cp _templates/template.py _work/py/b.py
cp _templates/template.py _work/py/c.py
cp _templates/template.py _work/py/d.py
cp _templates/template.py _work/py/e.py
cp _templates/template.py _work/py/f.py

# Set up Java working directory
mkdir -p _work/java
cp _templates/template.java _work/java/a.java
cp _templates/template.java _work/java/b.java
cp _templates/template.java _work/java/c.java
cp _templates/template.java _work/java/d.java
cp _templates/template.java _work/java/e.java
cp _templates/template.java _work/java/f.java

# Set up test I/O files
touch test.in
touch test.out
