# Run this script from the root project directory

# Set up C++ working directory
md _work/cc -ea 0
Copy-Item _templates/template.cc -Destination _work/cc/a.cc
Copy-Item _templates/template.cc -Destination _work/cc/b.cc
Copy-Item _templates/template.cc -Destination _work/cc/c.cc
Copy-Item _templates/template.cc -Destination _work/cc/d.cc
Copy-Item _templates/template.cc -Destination _work/cc/e.cc
Copy-Item _templates/template.cc -Destination _work/cc/f.cc

# Setup Python working directory
md _work/py -ea 0
Copy-Item _templates/template.py -Destination _work/py/a.py
Copy-Item _templates/template.py -Destination _work/py/b.py
Copy-Item _templates/template.py -Destination _work/py/c.py
Copy-Item _templates/template.py -Destination _work/py/d.py
Copy-Item _templates/template.py -Destination _work/py/e.py
Copy-Item _templates/template.py -Destination _work/py/f.py

# Set up test I/O files
New-Item test.in -ea 0
New-Item test.out -ea 0