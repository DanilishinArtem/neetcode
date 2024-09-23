class Solution:
    def climbStairs(n: int) -> int:
        one, two = 1, 1
        for _ in range(n - 1):
            temp = one
            one = one + two
            two = temp
        return one


if __name__ == "__main__":
    n = 3
    print('Input: {}'.format(n))
    print(Solution.climbStairs(n=n))