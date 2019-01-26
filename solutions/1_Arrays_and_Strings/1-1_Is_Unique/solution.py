# We can use:
# * Set/HashMap
# * Boolean array
# * Bit field
# * Sorting
# * Brute search

# Using a Set/HashMap
# O(N) time, O(N) space
# N == len(S)
# 9.491s
def solve(S):
    s = set()
    for ch in S:
        if ch in s:
            return False
        s.add(ch)
    return True

# # Using a bit-field
# # O(N) time, O(1) space
# # N == len(S)
# # 17.224s
# def solve(S):
#     # 256-bit bitfield: can only support 256 unique characters
#     mem = 0
#     for ch in S:
#         # Only support characters from ' ' onwards (ASCII = 32)
#         val = ord(ch) - ord(' ')
#         val = 1 << val
#         if mem & val > 0:
#             return False
#         mem |= val
#     return True

# # Sorting the string & checking for 2 adjacent, similar characters
# # O(NlogN) time, O(1) space
# # N == len(S)
# # 13.551s
# def solve(S):
#     S = ''.join(sorted(S))
#     # The iteration through the string takes O(N) time,
#     # but since sorting takes O(NlogN) time,
#     # sorting is the bottleneck here
#     for i in range(1, len(S)):
#         if S[i] == S[i - 1]:
#             return False
#     return True

# # For each char in the string, iterate through every other char
# # O(N^2) time, O(1) space
# # N == len(S)
# # 17.856s
# def solve(S):
#     N = len(S)
#     for i in range(N - 1):
#         for j in range(i + 1, N):
#             if S[i] == S[j]:
#                 return False
#     return True
