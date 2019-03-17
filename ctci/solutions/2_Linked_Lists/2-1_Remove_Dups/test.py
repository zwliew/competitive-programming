from solution import solve
from node import Node

def test(t):
    cur = Node(0)
    head = cur
    for i in range(1, 8):
        node = Node(i % 2)
        cur.nxt = node
        cur = node

    head = solve(head)
    t.assertEqual(str(head), '0 1')
