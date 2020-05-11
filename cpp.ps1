param([string]$file = "a")

clang++ --std=c++17 -O2 -static -pipe -fsanitize=address -Wall -Wextra -pedantic -Wfloat-equal -Wshadow-all -Wformat=2 -Wconversion -Wcast-qual -Wcast-align _work/cpp/$file.cc; ./a.exe
