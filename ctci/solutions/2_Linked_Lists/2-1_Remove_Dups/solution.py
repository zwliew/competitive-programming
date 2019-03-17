# # Uses a set to store the data that has been found
# # O(N) time, O(N) space
# # N == len(head)
# # 19.475s
# def solve(head):
#     s = set()
#     cur = head
#     prv = None
#     while cur:
#         if cur.val in s:
#             prv.nxt = cur.nxt
#         else:
#             s.add(cur.val)
#             prv = cur
#         cur = cur.nxt
#     return head

# Similar to solution 1, but tracks the current node differently
# O(N) time, O(N) space
# N == len(head)
# 19.992s
def solve(head):
    s = set([head.val])
    cur = head
    while cur.nxt:
        if cur.nxt.val in s:
            cur.nxt = cur.nxt.nxt
        else:
            s.add(cur.nxt.val)
            cur = cur.nxt
    return head

# # Iterate through the linked list with 2 pointers and check if
# # each node is different from every subsequent node
# # O(N^2) time, O(1) space
# # N == len(head)
# # 19.363s
# def solve(head):
#     cur = head
#     while cur:
#         run = cur
#         while run.nxt:
#             if cur.val == run.nxt.val:
#                 run.nxt = run.nxt.nxt
#             else:
#                 run = run.nxt
#         cur = cur.nxt
#     return head
