# # Stores the coords of zero elements
# # O(MN) time, O(M + N) space
# # M = len(A), N = len(A[0])
# # 36.930s
# def solve(A):
#     M = len(A)
#     N = len(A[0])
#     zeroes = []
#     for i in range(M):
#         for j in range(N):
#             if A[i][j] == 0:
#                 zeroes.append((i, j))

#     for el in zeroes:
#         y = el[0]
#         x = el[1]
#         A[y] = [0 for i in range(N)]
#         for i in range(M):
#             A[i][x] = 0

#     return A

# # Similar to solution 1, but stores the x and y coords of zeroes separately
# # O(MN) time, O(M + N) space
# # M = len(A), N = len(A[0])
# # 33.318s
# def solve(A):
#     M = len(A)
#     N = len(A[0])
#     x = []
#     y = []
#     for i in range(M):
#         for j in range(N):
#             if A[i][j] == 0:
#                 x.append(j)
#                 y.append(i)

#     for i in y:
#         A[i] = [0 for j in range(N)]

#     for i in x:
#         for j in range(M):
#             A[j][i] = 0

#     return A

# Similar to solution 2, but uses the first column and row of the
# input matrix as flags for whether the column or row should be set to zero
# O(MN) time, O(1) space
# M = len(A), N = len(A[0])
# 24.918s
def solve(A):
    M = len(A)
    N = len(A[0])
    first_col_zero = False
    first_row_zero = False

    for i in range(M):
        if A[i][0] == 0:
            first_col_zero = True
            break

    for i in range(N):
        if A[0][i] == 0:
            first_row_zero = True
            break

    for i in range(1, M):
        for j in range(1, N):
            if A[i][j] == 0:
                A[0][j] = 0
                A[i][0] = 0

    for i in range(M):
        if A[i][0] == 0:
            for j in range(N):
                A[i][j] = 0

    for i in range(N):
        if A[0][i] == 0:
            for j in range(M):
                A[j][i] = 0

    if first_col_zero:
        for i in range(M):
            A[i][0] = 0

    if first_row_zero:
        for i in range(N):
            A[0][i] = 0

    return A
