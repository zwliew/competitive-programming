class Solution:
    def solve(self, arr):
        # Write your code here
        colors = [-1 for i in range(len(arr))]

        def dfs(u):
            for v in arr[u]:
                if colors[v] == -1:
                    colors[v] = 0 if colors[u] == 1 else 1
                    if not dfs(v):
                        return False
                elif colors[v] == colors[u]:
                    return False
            return True

        colors[0] = 0
        return dfs(0)
