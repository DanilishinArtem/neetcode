class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if t == '': return ''
        countT, window = {}, {}
        for c in t:
            countT[c] = 1 + countT.get(c, 0)
        have, need = 0, len(countT)
        res, resLen = '', float('inf')
        l = 0
        for r in range(len(s)):
            c = s[r]
            window[c] = 1 + window.get(c, 0)
            if c in countT and window[c] == countT[c]:
                have += 1
            while have == need:
                # update our result
                if (r - l + 1) < resLen:
                    res = s[l:r+1]
                    resLen = (r - l + 1)
                # pop from the left of our window
                window[s[l]] -= 1
                if s[l] in countT and window[s[l]] < countT[s[l]]:
                    have -= 1
                l += 1
        return res if resLen != float('inf') else ''


        
        
if __name__ == "__main__":
    s = "ab"
    t = "b"
    print(Solution().minWindow(s, t))