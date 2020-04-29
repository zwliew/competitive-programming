from collections import deque, Counter, defaultdict
from functools import lru_cache
from itertools import permutations
from heapq import (
    heappush,
    heappop,
    heapreplace,
    heappushpop,
    heapify,
    merge,
    nlargest,
    nsmallest,
)
from statistics import mean, median, mode
from bisect import bisect_right, bisect_left
from math import floor, ceil, log2, log10, sqrt, factorial
from sys import maxsize, stdin


mod = int(1e9)
for line in stdin:
    args = line.split(" ")
    x = int(args[0]) % mod
    y = int(args[2]) % mod
    if args[1] == "+":
        ans = x + y
    elif args[1] == "*":
        ans = x * y
    elif args[1] == "^":
        ans = pow(x, y, mod)
    print(ans % 10000)
