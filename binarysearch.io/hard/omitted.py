class Solution:
    def solve(self, nums):
        # Write your code here
        r = [1]
        for i in range(1, len(nums)):
            r.append(r[i - 1] * nums[i - 1])
        x = 1
        for i in range(len(nums) - 2, -1, -1):
            x *= nums[i + 1]
            r[i] *= x
        return r
