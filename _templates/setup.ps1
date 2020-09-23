# Run this script from the root project directory

# Set up C++ working directory
md _work/cc -ea 0
Copy-Item _templates/template.cc -Destination _work/cc/a.cc
Copy-Item _templates/template.cc -Destination _work/cc/b.cc
Copy-Item _templates/template.cc -Destination _work/cc/c.cc
Copy-Item _templates/template.cc -Destination _work/cc/d.cc
Copy-Item _templates/template.cc -Destination _work/cc/e.cc
Copy-Item _templates/template.cc -Destination _work/cc/f.cc

# Set up Python working directory
md _work/py -ea 0
Copy-Item _templates/template.py -Destination _work/py/a.py
Copy-Item _templates/template.py -Destination _work/py/b.py
Copy-Item _templates/template.py -Destination _work/py/c.py
Copy-Item _templates/template.py -Destination _work/py/d.py
Copy-Item _templates/template.py -Destination _work/py/e.py
Copy-Item _templates/template.py -Destination _work/py/f.py

# Set up Java working directory
md _work/java -ea 0
Copy-Item _templates/template.java -Destination _work/java/a.java
Copy-Item _templates/template.java -Destination _work/java/b.java
Copy-Item _templates/template.java -Destination _work/java/c.java
Copy-Item _templates/template.java -Destination _work/java/d.java
Copy-Item _templates/template.java -Destination _work/java/e.java
Copy-Item _templates/template.java -Destination _work/java/f.java

# Set up JavaScript working directory
md _work/js -ea 0
Copy-Item _templates/template.js -Destination _work/js/a.js

# Set up test I/O files
New-Item test.in -ea 0
New-Item test.out -ea 0