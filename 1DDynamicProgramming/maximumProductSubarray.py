class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        dp = [1] * (len(nums) + 1)
        dp[1:] = nums.copy()
        for i in range(1, len(nums)):
            dp[i] = max(max(dp[:i]), nums[i-1] * dp[i-1])
            # dp[i] = max(dp[i-1] * nums[i], nums[i], dp[i] * nums[i])

        return max(dp)


if __name__ == "__main__":
    nums = [-2,0,-1]
    print("Input: {}".format(nums))
    print("Output: {}".format(Solution().maxProduct(nums)))