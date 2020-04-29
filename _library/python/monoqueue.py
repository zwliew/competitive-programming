import collections


class MonoQueue(collections.deque):
    def enqueue(self, val):
        count = 1
        while self and self[-1][0] < val:
            count += self.pop()[1]
        self.append([val, count])

    def dequeue(self):
        ans = self.max()
        self[0][1] -= 1
        if self[0][1] <= 0:
            self.popleft()
        return ans

    def max(self):
        return self[0][0] if self else 0


# Test code
q = MonoQueue()
nums = [4, 8, 3, 6, 0, 1, 0]
k = 0
for num in nums:
    q.enqueue(num)
    k += 1
    if k > 2:
        q.dequeue()
        k -= 1
    print(q.max())
