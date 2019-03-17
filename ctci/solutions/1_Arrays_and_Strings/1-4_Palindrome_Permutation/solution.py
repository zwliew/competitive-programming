# Definition: A string is a permutation of a palindrome if the number
#             of occurences of at most 1 character is odd. All other
#             characters can only occur an even number of times.
#
# Examples: If length of string is odd, 1 character occurs an odd number of times.
#           If length of string is even, all characters occur an even number of times.
#
# Possible solutions:
#  * Generating every permutation and checking it against the original string
#  * Checking the string against the definition above, storing occurences
#    using a hash table or a bit vector
#  * Using a bit vector similar to using a hash table

# # Using a hash table to store the number of occurences of each character
# # O(N) time, O(N) space
# # 59.796s
# def solve(S):
#     # The palindrome check is case-insensitive
#     S = ''.join(S.split(' ')).lower()

#     h = {}
#     for c in S:
#         if c not in h:
#             h[c] = 1
#         else:
#             h[c] += 1

#     odd_found = False
#     for k, v in h.items():
#         if v % 2 != 0:
#             if odd_found:
#                 return False
#             odd_found = True

#     return True

# # Similar to the first solution of using a hash table,
# # but the odd number check is done during the initial iteration
# # O(N) time, O(N) space
# # 66.458s
# def solve(S):
#     # The palindrome check is case-insensitive
#     S = ''.join(S.split(' ')).lower()

#     odd_cnt = 0
#     h = {}
#     for c in S:
#         if c not in h:
#             h[c] = 1
#             odd_cnt += 1
#         else:
#             h[c] += 1
#             if h[c] % 2 == 1:
#                 odd_cnt += 1
#             else:
#                 odd_cnt -= 1

#     return odd_cnt <= 1

# Using a bit vector to store whether a character was encountered
# an even or odd number of times
# Use bit manipulation
# O(N) time, O(1) space
# 67.746s
def solve(S):
    # The palindrome check is case-insensitive
    S = ''.join(S.split(' ')).lower()

    # Assume the characters are from 'a' to 'z' (0 - 26)
    a = ord('a')
    b_vec = 0
    for c in S:
        val = ord(c) - a
        # Flip the 'switch' for the state of the current character
        # 1 == odd number of occurences
        # 0 == 0 or even number of occurences
        b_vec ^= 1 << val

    # Check if *at most* 1 bit is 1
    # 0000 & (0000 - 1) == 0000 & 0000 == 0
    # 0100 & (0100 - 1) == 0100 & 0011 == 0
    # 0110 & (0110 - 1) == 0110 & 0101 == 0100 > 0
    return b_vec & (b_vec - 1) == 0
