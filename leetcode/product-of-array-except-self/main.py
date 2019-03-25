from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [1 for i in range(len(nums))]
        for i in range(1, len(nums)):
            result[i] = result[i - 1] * nums[i - 1]

        cur_prod = 1
        for i in range(len(nums) - 2, -1, -1):
            cur_prod *= nums[i + 1]
            result[i] *= cur_prod

        return result
