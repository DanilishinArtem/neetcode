class Solution:
    def findTargetSumWays(self, nums: list[int], target: int) -> int:
        dp = {} # (index, total) -> # of ways

        def backtrack(index, total):
            if index == len(nums):
                return 1 if total == target else 0
            if (index, total) in dp:
                return dp[(index, total)]
            dp[(index, total)] = backtrack(index + 1, total + nums[index]) + backtrack(index + 1, total - nums[index])
            return dp[(index, total)]

        return backtrack(0, 0)


if __name__ == "__main__":
    nums = [1, 1, 1, 1, 1]
    target = 3
    print(f'Input: {nums}, {target}')
    print(f'Output: {Solution().findTargetSumWays(nums, target)}')