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


def lcm(a, b):
    p = a * b
    while b:
        a %= b
        a, b = b, a
    return p // a


n = int(input())
a = list(map(int, input().split(" ")))
alcm = a[0]
for i in a:
    alcm = lcm(alcm, i)

tot = 0
for num in a:
    tot += alcm // num

print(tot % 1000000007)
