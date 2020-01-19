def gcd(a,b):
  if b == 0:
    return a
  return gcd(b, a % b)

def lcm(a,b):
  return a * b // gcd(a,b)

n = int(input())
av = list(map(int, input().split(' ')))
alcm = 1
for i in av:
  alcm = lcm(alcm, i)

tot = 0
for i in range(n):
  tot += alcm // av[i]

print(tot % 1000000007)