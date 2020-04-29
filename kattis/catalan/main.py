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
from sys import maxsize

# Use the recursive relation
# q = int(input())
# queries = []
# xmax = 0
# while q:
#     x = int(input())
#     queries.append(x)
#     xmax = max(x, xmax)
#     q -= 1

# cat = [1]
# for i in range(xmax):
#     cat.append(cat[i] * 2 * (i * 2 + 1) // (i + 2))

# for x in queries:
#     print("{:d}".format(cat[x]))

# Alternative implementation using the analytical formula
q = int(input())
while q:
    x = int(input())
    print(factorial(x * 2) // factorial(x) ** 2 // (x + 1))
    q -= 1
