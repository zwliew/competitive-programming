param([string]$file = "a")

Get-Content test.in | python _work/py/$file.py > test.out
