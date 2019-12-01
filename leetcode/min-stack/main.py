class MinStack:
    def __init__(self):
        """
        initialize your data structure here.
        """
        self.s = []
        self.minx = 1e9 + 1


    def push(self, x: int) -> None:
        if len(self.s) == 0:
            self.s.append(x)
            self.minx = x
        elif x >= self.minx:
            self.s.append(x)
        else:
            self.s.append(2 * x - self.minx)
            self.minx = x

    def pop(self) -> None:
        if len(self.s) == 0:
            return

        x = self.s[-1]
        self.s.pop()

        if x < self.minx:
            self.minx = 2 * self.minx - x

    def top(self) -> int:
        return self.s[-1] if self.s[-1] >= self.minx else self.minx

    def getMin(self) -> int:
        return self.minx


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()