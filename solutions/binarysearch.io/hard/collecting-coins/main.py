class Solution:
2    def solve(self, matrix):
3        from functools import lru_cache
4        @lru_cache(None)
5        def dp(i, j):
6            if i < 0 or j < 0:
7                return 0
8            return max(dp(i - 1, j), dp(i, j - 1)) + matrix[i][j]
9        return dp(len(matrix) - 1, len(matrix[0]) - 1)
