class Solution:
    def isValid(self, s: str) -> bool:
        pairs = {')': '(', '}': '{', ']': '['}
        st = []
        for c in s:
            if c in ['{', '[', '(']:
                st.append(c)
            elif len(st) > 0 and st[len(st) - 1] == pairs[c]:
                st.pop()
            else:
                return False
        return len(st) == 0
