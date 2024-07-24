class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        hashmap = {}
        for c in s1:
            hashmap[c] = 1 + hashmap.get(c, 0)
        
        l = 0
        for r in range(len(s2)):
            if s2[r] in hashmap:
                hashmap[s2[r]] -= 1
                if hashmap[s2[r]] == 0:
                    hashmap.pop(s2[r])
            else:
                while l < r:
                    hashmap[s2[l]] = 1 + hashmap.get(s2[l], 0)
                    l += 1
            
            if len(hashmap) == 0:
                return True
            
        return False
    

if __name__ == "__main__":
    s1 = "ab"
    s2 = "eidbaooo"
    print(Solution().checkInclusion(s1, s2))