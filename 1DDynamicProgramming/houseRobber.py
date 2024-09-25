class Solution:
    def rob(self, nums: list[int]) -> int:
        rob1 = nums[0]
        rob2 = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            temp = max(rob1 + nums[i], rob2)
            rob1 = rob2
            rob2 = temp
        return rob2


if __name__ == "__main__":
    input = [1, 1, 3, 3]
    print("Input: {}".format(input))
    print("Output: {}".format(Solution().rob(input)))