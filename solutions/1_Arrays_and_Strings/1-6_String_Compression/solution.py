# # Build up a new compressed string while iterating through the input
# # O(N) time, O(N) space
# # N == len(S)
# # 13.788s
# def solve(S):
#     res_str = []
#     cur_ch = None
#     cur_cnt = 0
#     for c in S:
#         if c != cur_ch:
#             if cur_ch is not None:
#                 res_str.append(cur_ch)
#                 res_str.append(str(cur_cnt))
#             cur_ch = c
#             cur_cnt = 1
#         else:
#             cur_cnt += 1

#     if cur_ch is not None:
#         res_str.append(cur_ch)
#         res_str.append(str(cur_cnt))

#     return ''.join(res_str) if len(res_str) < len(S) else S

# Similar to solution 1, but with a slightly different mode of iteration
# O(N) time, O(N) space
# N == len(S)
# 15.538s
def solve(S):
    N = len(S)
    res_str = []
    cur_cnt = 0
    for i in range(N):
        cur_cnt += 1
        c = S[i]
        if i + 1 >= N or S[i + 1] != c:
            res_str.append(c)
            res_str.append(str(cur_cnt))
            cur_cnt = 0
    return ''.join(res_str) if len(res_str) < N else S

# # Similar to solution 1 and 2, but does not create a new string if
# # the length of the compressed string will not be shorter than the original
# # O(N) time, O(N) space
# # 32.549s
# def solve(S):
#     N = len(S)
#     def compressed_len(S, N):
#         length = 0
#         cur_cnt = 0
#         for i in range(N):
#             cur_cnt += 1

#             if i + 1 >= N or S[i + 1] != S[i]:
#                 length += 1 + len(str(cur_cnt))
#                 cur_cnt = 0
#         return length

#     if compressed_len(S, N) >= N:
#         return S

#     res_str = []
#     cur_cnt = 0
#     for i in range(N):
#         cur_cnt += 1
#         c = S[i]
#         if i + 1 >= N or S[i + 1] != c:
#             res_str.append(c)
#             res_str.append(str(cur_cnt))
#             cur_cnt = 0

#     return ''.join(res_str)
