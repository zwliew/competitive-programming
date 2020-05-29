#!/usr/bin/env python3

import functools

T = int(input())
for t in range(T):
    N = input()
    if N == "":
        N = int(input())
    else:
        N = int(N)
    cities = input().split(" ")
    cities = [int(s) for s in cities[: len(cities) - 1]]
    P = int(input())
    counts = [0 for i in range(P)]
    for p in range(P):
        city = int(input())
        for i in range(len(cities) // 2):
            a = cities[i * 2]
            b = cities[i * 2 + 1]
            if city >= a and city <= b:
                counts[p] += 1
    print(
        "Case #{}: {}".format(
            t + 1, functools.reduce(lambda x, y: x + " " + str(y), counts, "")
        )
    )

