class FenwickTree:
    def __init__(self, arr):
        self.n = len(arr) + 1
        self.bit1 = [0 for i in range(self.n)]
        self.bit2 = [0 for i in range(self.n)]

        for i in range(len(arr)):
            self.range_update(i, i, arr[i])

    def update(self, bit, idx, val):
        idx += 1
        while idx < self.n:
            bit[idx] += val
            idx += idx & -idx

    def query(self, bit, idx):
        idx += 1
        res = 0
        while idx > 0:
            res += bit[idx]
            idx -= idx & -idx
        return res

    def range_update(self, l, r, val):
        self.update(self.bit1, l, val)
        self.update(self.bit1, r + 1, -val)
        self.update(self.bit2, l, val * (l - 1))
        self.update(self.bit2, r + 1, -val * r)

    def prefix_query(self, idx):
        return self.query(self.bit1, idx) * idx - self.query(self.bit2, idx)

    def range_query(self, l, r):
        return self.prefix_query(r) - self.prefix_query(l - 1)
