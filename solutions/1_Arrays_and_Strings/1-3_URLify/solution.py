# # Creating a new string & iterating through the original string
# # to insert the corresponding characters into the new string
# # O(N) time, O(N) space
# # 19.988s
# def solve(S, N):
#     ret = []
#     for i in range(N):
#         if S[i] == ' ':
#             ret.append('%')
#             ret.append('2')
#             ret.append('0')
#         else:
#             ret.append(S[i])
#     return ret

# Modifying the string in place by copying over characters
# from the 'end' of the original string to the true end
# of the entire string, which includes the buffer.
# There is no risk of collision with the original string since
# the buffer is already at the end of the string.
# O(N) time, O(1) space
# 21.764s
def solve(S, N):
    idx = len(S) - 1
    for i in range(N - 1, -1, -1):
        if S[i] == ' ':
            S[idx - 2:idx + 1] = '%20'
            idx -= 3
        else:
            S[idx] = S[i]
            idx -= 1
    return S
