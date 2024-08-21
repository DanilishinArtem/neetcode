class Solution:
    def subsetsWithDup(self, nums: list[int]) -> list[list[int]]:
        res = []
        nums.sort()
        def backtrack(i, nums, subset):
            if i >= len(nums):
                res.append(subset.copy())
                return
            subset.append(nums[i])
            backtrack(i + 1, nums, subset)
            subset.pop()
            while i + 1 < len(nums) and nums[i + 1] == nums[i]:
                i += 1
            backtrack(i + 1, nums, subset)
        backtrack(0, nums, [])
        return res



if __name__ == "__main__":
    nums = [1, 2, 2]
    print("Input: " + str(nums))
    print("Output: " + str(Solution().subsetsWithDup(nums)))