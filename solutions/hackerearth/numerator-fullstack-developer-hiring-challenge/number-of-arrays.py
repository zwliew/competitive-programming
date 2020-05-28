t = int(input())
nList = []
maxN = 0
for _ in range(t):
    n = int(input())
    maxN = max(maxN, n)
    nList.append(n)

answers = {}
numWays = [0] * 8
numWays[0] = 1
for n in range(1, maxN + 1):
    nextNumWays = [0] * 8
    for j in range(8):
        for k in range(6):
            nextNumWays[j] = (nextNumWays[j] + numWays[j ^ k]) % 1000000007
    numWays = nextNumWays
    answers[n] = numWays[0]

for n in nList:
    print(answers[n])
