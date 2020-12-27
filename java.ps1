param([string]$file="a")

Get-Content test.in | java _work/java/$file.java > test.out
