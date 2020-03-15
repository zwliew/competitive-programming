a, b, c = list(map(int, input().split()))
if c > a and c > b and 4 * a * b < (c - a - b) ** 2:
    print("Yes")
else:
    print("No")

