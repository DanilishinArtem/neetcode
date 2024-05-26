# based on sorting algo time complexity is O(m*n*logn) and space complexity is O(n)
# hashmap algo time complexity is O(n*m*26) ~ O(n*m)

class Solution(object):
    def groupAnagrams(self, strs):
        hashMap = defaultdict(list) # list of mapping charCount to List of anagrams
        for s in strs:
            count = [0] * 26 # a - z
            for c in s:
                count[ord(c) - ord('a')] += 1
            hashMap[tuple(count)].append(s)
        return hashMap.values()
        

