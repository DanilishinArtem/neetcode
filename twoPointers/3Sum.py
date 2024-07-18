class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        result = []
        for ind, val in enumerate(nums):
            hashMap = {}
            for i in range(0, len(nums)):
                if i != ind:
                    if str(-val - nums[i]) not in hashMap:
                        hashMap[str(nums[i])] = i
                    else:
                        temp = sorted([nums[ind], nums[i], nums[hashMap[str(-val - nums[i])]]])
                        if temp not in result:
                            result.append(temp)
        return result
    

if __name__ == "__main__":
    nums = [-1,0,1,2,-1,-4]
    print(Solution().threeSum(nums))