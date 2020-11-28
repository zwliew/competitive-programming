import collections, functools, itertools, heapq, statistics, bisect, math, sys, random, time, datetime, csv, re, multiprocessing
from collections import deque, Counter, defaultdict, OrderedDict
from functools import lru_cache
from itertools import permutations, accumulate
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

# from sortedcontainers import SortedList, SortedDict, SortedSet
from random import seed, randrange, randint, random, choice, choices
from time import localtime, strftime, mktime
from datetime import datetime
from csv import reader, writer
from re import search
from multiprocessing import Pool

if __name__ == "__main__":
    n = int(input())
    vals = [1]
    while n != 0:
        ans = []
        idx = 0
        n -= 1
        if not n:
            print("{ }")
        else:
            while n:
                if n & 1:
                    while len(vals) <= idx:
                        vals.append(vals[-1] * 3)
                    ans.append(str(vals[idx]))
                idx += 1
                n >>= 1
            print("{ " + f"{', '.join(ans)}" + " }")
        n = int(input())
