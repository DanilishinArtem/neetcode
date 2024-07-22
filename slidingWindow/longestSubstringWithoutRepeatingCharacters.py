class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        hash_table = {}
        for char in ' abcdefghijklmnopqrstuvwxyz':
            hash_table[char] = 0
        left = 0
        hash_table[s[left]] = 1
        right = 1
        maxLen = right - left
        while right < len(s):
            if hash_table[s[right]] == 0:
                hash_table[s[right]] = 1
                right += 1
                maxLen = max(maxLen, right - left)
            else:
                hash_table[s[left]] -= 1
                left += 1
        return maxLen
    

if __name__ == "__main__":
    s = " "
    print(Solution().lengthOfLongestSubstring(s))
