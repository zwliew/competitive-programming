class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        j = len(nums) - 1
        while True:
            while i < len(nums) and nums[i] != val:
                i += 1

            while j >= 0 and nums[j] == val:
                j -= 1

            if j <= i:
                return j + 1

            nums[i], nums[j] = nums[j], nums[i]
        return j + 1

# Solution 2
# class Solution:
#     def removeElement(self, nums: List[int], val: int) -> int:
#         i = 0
#         for j in range(len(nums)):
#             if nums[j] != val:
#                 nums[i] = nums[j]
#                 i += 1
#         return i

# Solution 3
# class Solution:
#     def removeElement(self, nums: List[int], val: int) -> int:
#         i = 0
#         n = len(nums)
#         while i < n:
#             if nums[i] == val:
#                 nums[i] = nums[n - 1]
#                 n -= 1
#             else:
#                 i += 1
#         return n