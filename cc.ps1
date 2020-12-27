param([string]$file="a")

make x=$file
Get-Content test.in | ./a.exe > test.out
