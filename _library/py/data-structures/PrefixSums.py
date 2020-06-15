import itertools


class PrefixSums1D(list):
    def __init__(self, arr: list):
        self.append(0)
        self.extend(list(itertools.accumulate(arr)))
        print(self)

    def query(self, l: int, r: int) -> int:
        return self[r + 1] - self[l]
