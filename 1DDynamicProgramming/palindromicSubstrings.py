class Solution:
    def countSubstrings(self, s: str) -> int:
        nSubstrings = 0
        for i in range(len(s)):
            # odd len
            l, r = i, i
            while l >= 0 and r < len(s) and s[l] == s[r]:
                nSubstrings += 1
                l -= 1
                r += 1

            # even len
            l, r = i, i + 1
            while l >= 0 and r < len(s) and s[l] == s[r]:
                nSubstrings += 1
                l -= 1
                r += 1
        
        return nSubstrings


if __name__ == '__main__':
    input = "abc"
    print("Input: {}".format(input))
    print("Output: {}".format(Solution().countSubstrings(input)))