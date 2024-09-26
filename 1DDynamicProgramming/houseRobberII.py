class Solution:
    def rob(self, nums: list[int]) -> int:
        return max(nums[0], self.helper(nums[1:]), self.helper(nums[:-1]))
    
    def helper(self, nums: list[int]) -> int:
        rob1, rob2 = 0, 0
        for n in nums:
            temp = max(rob1 + n, rob2)
            rob1 = rob2
            rob2 = temp
        return rob2


if __name__ == '__main__':
    nums = [2, 3, 2]
    print("Input: {}".format(nums))
    print("Output: {}".format(Solution().rob(nums)))