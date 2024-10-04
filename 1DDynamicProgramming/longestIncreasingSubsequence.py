class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        dp = [1] * len(nums)

        for i in range(len(nums) - 1, -1, -1):
            for j in range(i + 1, len(nums)):
                if nums[i] < nums[j]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)


if __name__ == '__main__':
    s = Solution()
    nums = [3,1,2]
    print("Input: {}".format(nums))
    print("Output: {}".format(s.lengthOfLIS(nums)))