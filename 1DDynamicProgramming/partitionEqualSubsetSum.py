class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        if sum(nums) % 2:
            return False
        
        target = sum(nums) // 2
        dp = set()
        dp.add(0)
        for i in range(len(nums) - 1, -1, -1):
            nextDp = set()
            for t in dp:
                nextDp.add(t + nums[i])
                nextDp.add(t)
            dp = nextDp
        return True if target in dp else False
    

if __name__ == "__main__":
    input = [1, 5, 11, 5]
    print("Input: {}".format(input))
    print("Output: {}".format(Solution().canPartition(input)))