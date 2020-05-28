class Solution:
    def numOfSubarrays(self, arr: List[int], k: int, threshold: int) -> int:
        cnt = 0
        cursum = 0
        tot = 0
        for i in range(len(arr)):
            if cnt < k:
                cnt += 1
                cursum += arr[i]
                if cnt == k:
                    if cursum // k >= threshold:
                        tot += 1
            else:
                cursum -= arr[i - k]
                cursum += arr[i]
                if cursum // k >= threshold:
                    tot += 1
        return tot