class Solution:
    def minSteps(self, s: str, t: str) -> int:
        cnt = {}
        for i in s:
            if i not in cnt:
                cnt[i] = 1
            else:
                cnt[i] += 1
        nextcnt = {}
        for i in t:
            if i not in nextcnt:
                nextcnt[i] = 1
            else:
                nextcnt[i] += 1
        r = 0
        for k,v in nextcnt.items():
            if k not in cnt:
                r += v
            else:
                if v > cnt[k]:
                    r += v - cnt[k]
        return r