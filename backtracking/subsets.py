class Solution:
    def subsets(self, nums: list[int]) -> list[list[int]]:
        res = []
        subset = []

        def dfs(index: int):
            if index >= len(nums):
                res.append(subset.copy())
                return
            # decision to include nums[index]
            subset.append(nums[index])
            dfs(index + 1)

            # decision NOT to include nums[index]
            subset.pop()
            dfs(index + 1)

        dfs(0)
        return res


if __name__ == "__main__":
    nums = [1, 2, 3]
    print("Input: " + str(nums))
    print("Solution: " + str(Solution().subsets(nums)))