class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        res = max(nums)
        curMin, curMax = 1, 1

        for n in nums:
            if n == 0:
                curMin, curMax = 1, 1
                continue

            tmp = curMax * n
            curMax = max(n * curMax, n * curMin, n)
            curMin = min(tmp, n * curMin, n)
            res = max(res, curMax)

        return res


if __name__ == "__main__":
    nums = [-4,-3,-2]
    print("Input: {}".format(nums))
    print("Output: {}".format(Solution().maxProduct(nums)))