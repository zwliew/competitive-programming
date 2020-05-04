from collections import deque, Counter, defaultdict, OrderedDict
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
    _heappop_max,
    _heapify_max,
    _heapreplace_max,
    _siftdown_max,
)
from statistics import mean, median, mode
from bisect import bisect_right, bisect_left
from math import (
    floor,
    ceil,
    log2,
    log,
    log10,
    sqrt,
    factorial,
    gamma,
    lgamma,
    pi,
    e,
    inf,
)
from sys import maxsize, stdin

n, k = map(int, input().split())
if 2 ** k >= n:
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")
