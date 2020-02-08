class Solution:
    def minJumps(self, arr: List[int]) -> int:
        loc = {}
        for i in range(len(arr)):
            if arr[i] not in loc:
                loc[arr[i]] = [i]
            else:
                loc[arr[i]].append(i)

        mem = [1e9 for i in range(len(arr))]
        q = collections.deque()
        q.append((len(arr) - 1, 0))
        while len(q) > 0:
            x, y = q.popleft()
            if y >= mem[x]:
                continue
            if x == 0:
                return y
            mem[x] = y
            if x + 1 < len(arr) and mem[x + 1] > y + 1:
                if x + 1 == 0:
                    return y + 1
                q.append((x + 1, y + 1))
            if x - 1 >= 0 and mem[x - 1] > y + 1:
                if x - 1 == 0:
                    return y + 1
                q.append((x - 1, y + 1))
            for i in loc[arr[x]]:
                if i == 0:
                    return y + 1
                if mem[i] > y + 1:
                    q.append((i, y + 1))