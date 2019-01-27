# Options: handle the cases separately, or all in one pass
# Note: adding 1 character is the same as removing 1 character,
#       so both can be categorized under 1 case

# # Maintaining a separate index for iterating each string
# # and checking for at most 1 edit between both strings.
# # O(N) time, O(1) space
# # N == len(shorter string)
# # 76.747s
# def solve(A, B):
#     N_A = len(A)
#     N_B = len(B)

#     N_DELTA = N_A - N_B
#     if N_DELTA > 1 or N_DELTA < -1:
#         return False

#     if N_A == N_B:
#         diff_length = False
#         short_iter = A
#         long_iter = B
#         short_len = N_A
#         long_len = N_B
#     elif N_A < N_B:
#         diff_length = True
#         short_iter = A
#         long_iter = B
#         short_len = N_A
#         long_len = N_B
#     else:
#         diff_length = True
#         short_iter = B
#         long_iter = A
#         short_len = N_B
#         long_len = N_A

#     # Iterate through both strings simultaneously
#     found_edit = False
#     i = 0
#     j = 0
#     while i < short_len and j < long_len:
#         if short_iter[i] != long_iter[j]:
#             if found_edit:
#                 return False
#             found_edit = True

#             # Don't increment the index for the shorter string
#             if diff_length:
#                 i -= 1

#         i += 1
#         j += 1

#     return True

# Similar to the first solution, but with a slightly different
# method of iteration and predicate checking
# O(N) time, O(1) space
# N == len(shorter string)
# 70.791s
def solve(A, B):
    N_A = len(A)
    N_B = len(B)

    N_DELTA = N_A - N_B
    if N_DELTA > 1 or N_DELTA < -1:
        return False

    if N_A == N_B:
        diff_length = False
        short_iter = A
        long_iter = B
        short_len = N_A
    elif N_A < N_B:
        diff_length = True
        short_iter = A
        long_iter = B
        short_len = N_A
    else:
        diff_length = True
        short_iter = B
        long_iter = A
        short_len = N_B

    # Iterate through both strings simultaneously
    found_edit = False
    j = 0
    for i in range(short_len):
        s = short_iter[i]
        if s != long_iter[j]:
            # There can only be at most 1 edit
            if found_edit:
                return False
            found_edit = True

            # If one of the strings is longer, we check if
            # only 1 character is missing from the shorter string
            # and that the subsequent characters are the same
            if diff_length:
                j += 1
                if s != long_iter[j]:
                    return False

        j += 1

    return True
