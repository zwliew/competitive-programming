# For updating point indices, querying range sums
class PURQFenwickTree(list):
    def __init__(self, n: int):
        self.extend([0 for _ in range(n + 1)])

    def update(self, idx: int, val: int) -> None:
        idx += 1
        while idx < len(self):
            self[idx] += val
            idx += idx & -idx

    def query(self, idx: int) -> int:
        res = 0
        idx += 1
        while idx:
            res += self[idx]
            idx -= idx & -idx
        return res


# For updating range indices, querying point indices
class RUPQFenwickTree(list):
    def __init__(self, n: int):
        self.extend([0 for _ in range(n + 1)])

    def __update(self, idx: int, val: int) -> None:
        idx += 1
        while idx < len(self):
            self[idx] += val
            idx += idx & -idx

    def update(self, l: int, r: int, val: int) -> None:
        self.__update(l, val)
        self.__update(r + 1, -val)

    def query(self, idx: int) -> int:
        res = 0
        idx += 1
        while idx:
            res += self[idx]
            idx -= idx & -idx
        return res


# For updating range indices, querying range sums
class RURQFenwickTree:
    def __init__(self, n: int):
        self.t1 = [0 for i in range(n + 1)]
        self.t2 = [0 for i in range(n + 1)]

    def __update(self, t: list, idx: int, val: int) -> None:
        idx += 1
        while idx < len(t):
            t[idx] += val
            idx += idx & -idx

    def __query(self, t: list, idx: int) -> int:
        res = 0
        idx += 1
        while idx:
            res += t[idx]
            idx -= idx & -idx
        return res

    def update(self, l: int, r: int, val: int) -> None:
        self.__update(self.t1, l, val)
        self.__update(self.t1, r + 1, -val)
        self.__update(self.t2, l, val * (l - 1))
        self.__update(self.t2, r + 1, -val * r)

    def __prefix_query(self, idx: int) -> int:
        return self.__query(self.t1, idx) * idx - self.__query(self.t2, idx)

    def query(self, l, r):
        return self.__prefix_query(r) - self.__prefix_query(l - 1)
