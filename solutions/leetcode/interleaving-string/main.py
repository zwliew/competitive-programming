from functools import lru_cache


class Solution:
    def isInterleave(self, s0, s1, s2):
        @lru_cache(None)
        def dp(i, j, k):
            if i == -1 and j == -1 and k == -1:
                return True
            if k == -1:
                return False

            return (i >= 0 and k >= 0 and s0[i] == s2[k] and dp(i - 1, j, k - 1)) or (
                j >= 0 and k >= 0 and s1[j] == s2[k] and dp(i, j - 1, k - 1)
            )

        return dp(len(s0) - 1, len(s1) - 1, len(s2) - 1)
