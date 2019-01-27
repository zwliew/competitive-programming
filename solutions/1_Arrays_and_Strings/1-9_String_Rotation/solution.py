# s1 = xy
# s2 = yx
# (s1)(s1) = xyxy = x(yx)y = x(s2)y (s2 is a substring is (s1)(s1))
def is_substring(string, sub):
    return string.find(sub) != -1

# # O(N) time?
# # N == len(s1) + len(s2)
# # 21.866s
# def solve(s1, s2):
#     if len(s2) != len(s1):
#         return False

#     for i in range(len(s1)):
#         sub = s1[i:]
#         if is_substring(s2, sub):
#             return s2[len(sub):] == s1[:i]
#     return False

# O(N) time?
# N == len(s1) + len(s2)
# 7.756s
def solve(s1, s2):
    return len(s2) == len(s1) and is_substring(s1 + s1, s2)
