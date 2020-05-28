# For 2 strings (A and B) to be permutations of each other:
# * len(A) == len(B)
# * count(each character in A) == count(each character in B)
#
# We can use:
# * HashMap to count the number of occurences of each character
# * Integer array (similar to a HashMap, but only works for character
#                  sets smaller than or equal to the size of the array)
# * Sorting & iterating through both strings simultaneously

# Using a HashMap
# O(N) time, O(N) space
# N == len(A) == len(B)
# 16.768s
def solve(A, B):
    if len(A) != len(B):
        return False
    mem = {}
    for ch in A:
        if ch in mem:
            mem[ch] += 1
        else:
            mem[ch] = 1
    for ch in B:
        if ch not in mem or mem[ch] == 0:
            return False
        mem[ch] -= 1
    return True

# # Using a Counter (a dict/HashMap subclass in Python)
# # O(N) time, O(N) space
# # N == len(A) == len(B)
# # 55.198s
# from collections import Counter
# def solve(A, B):
#     if len(A) != len(B):
#         return False
#     c = Counter(A)
#     for ch in B:
#         if c[ch] == 0:
#             return False
#         c[ch] -= 1
#     return True

# # Sorting & iterating through both strings simultaneously
# # O(NlogN) time, O(1) space
# # N == len(A) == len(B)
# # NB: I think ''.join(sorted()) creates a new array/string,
# #     so does that mean that this actually takes O(N) space?
# # 9.695s
# def solve(A, B):
#     if len(A) != len(B):
#         return False
#     return sorted(A) == sorted(B)
