# for i = 0 to n
#   tmp = top[i]
#   top[i] = left[i]
#   left[i] = bottom[i]
#   bottom[i] = right[i]
#   right[i] = tmp
# O(N^2) time
# N == len(A)
# 16.857s
def solve(A):
    N = len(A)
    for i in range(N // 2):
        for j in range(i, N - i - 1):
            tmp = A[i][j]
            A[i][j] = A[N - 1 - j][i]
            A[N - 1 - j][i] = A[N - 1 - i][N - 1 - j]
            A[N - 1 - i][N - 1 - j] = A[j][N - 1 - i]
            A[j][N - 1 - i] = tmp

    return A
