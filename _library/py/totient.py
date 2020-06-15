import math


def phi(n):
    if n == 0:
        return 0

    res = n
    if n % 2 == 0:
        while n % 2 == 0:
            n //= 2
        res -= res // 2
    for i in range(3, math.floor(math.sqrt(n)) + 1, 2):
        if n % i == 0:
            while n % i == 0:
                n //= i
            res -= res // i
    if n > 1:
        res -= res // n

    return res


def phi1ToNDivisorSum(n):
    phi = [i - 1 for i in range(n + 1)]
    phi[0] = 0
    phi[1] = 1
    for i in range(2, n // 2 + 1):
        for j in range(i * 2, n + 1, i):
            phi[j] -= phi[i]
    return phi


def phi1ToNSieve(n):
    phi = [i for i in range(n + 1)]
    for i in range(2, n + 1, 2):
        phi[i] -= phi[i] / 2
    for i in range(3, n + 1, 2):
        if phi[i] == i:
            for j in range(i, n + 1, i):
                phi[j] -= phi[j] / i
    return phi
