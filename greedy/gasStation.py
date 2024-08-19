class Solution:
    def canCompleteCircuit(self, gas: list[int], cost: list[int]) -> int:
        if sum(gas) < sum(cost):
            return -1
        
        total, res = 0, 0
        for i in range(len(gas)):
            total += gas[i] - cost[i]
            if total < 0:
                total = 0
                res = i + 1
        return res
    


if __name__ == "__main__":
    gas = [1,2,3,4,5]
    cost = [3,4,5,1,2]
    print("Input: (gas:" + str(gas) + ", cost: " + str(cost) + ")")
    print("Output:")
    print(Solution().canCompleteCircuit(gas, cost))