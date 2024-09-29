class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        dp = [float("inf")] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            for c in coins:
                if i - c >= 0:
                    dp[i] = min(dp[i], dp[i - c] + 1)
        return dp[amount] if dp[amount] != float("inf") else -1


if __name__ == "__main__":
    coins = [1, 2, 5]
    amount = 11
    print("Input: coins = {}, amount = {}".format(coins, amount))
    print("Output: {}".format(Solution().coinChange(coins, amount)))