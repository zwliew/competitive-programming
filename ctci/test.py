from solution import solve
from node import Node

def test(t):
    cur = Node(0)
    head = cur
    for i in range(1, 8):
        node = Node(i)
        cur.nxt = node
        cur = node

    t.assertEqual(solve(head, 3), '4')
