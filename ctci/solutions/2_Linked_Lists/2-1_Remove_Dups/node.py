class Node:
    def __init__(self, val, nxt=None):
        self.nxt = nxt
        self.val = val

    def __str__(self):
        if self.nxt is None:
            return str(self.val)
        return str(self.val) + ' ' + str(self.nxt)

    def __len__(self):
        if self.nxt is None:
            return 1
        return 1 + len(self.nxt)
