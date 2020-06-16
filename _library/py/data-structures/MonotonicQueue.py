import collections


class MinMonotonicQueue(collections.deque):
    def enqueue(self, val: int) -> None:
        cnt = 1
        while self and self[-1][0] > val:
            cnt += self.pop()[1]
        self.append([val, cnt])

    def dequeue(self) -> int:
        res = self.top()
        self[0][1] -= 1
        if self[0][1] == 0:
            self.popleft()
        return res

    def top(self) -> int:
        return self[0][0]

    def min(self) -> int:
        return self.top()


class MaxMonotonicQueue(collections.deque):
    def enqueue(self, val: int) -> None:
        cnt = 1
        while self and self[-1][0] < val:
            cnt += self.pop()[1]
        self.append([val, cnt])

    def dequeue(self) -> int:
        ans = self.top()
        self[0][1] -= 1
        if self[0][1] == 0:
            self.popleft()
        return ans

    def top(self) -> int:
        return self[0][0]

    def max(self) -> int:
        return self.top()


class MinMaxMonotonicQueue:
    def __init__(self):
        self.minq = MinMonotonicQueue()
        self.maxq = MaxMonotonicQueue()

    def enqueue(self, val: int) -> None:
        self.minq.enqueue(val)
        self.maxq.enqueue(val)

    def dequeue(self) -> tuple:
        return (self.minq.dequeue(), self.maxq.dequeue())

    def top(self) -> tuple:
        return (self.minq.top(), self.maxq.top())

    def minMax(self) -> tuple:
        return self.top()


# Test code
q = MaxMonotonicQueue()
nums = [4, 8, 3, 6, 0, 1, 0]
k = 0
for num in nums:
    q.enqueue(num)
    k += 1
    if k > 2:
        q.dequeue()
        k -= 1
    print(q.top())
