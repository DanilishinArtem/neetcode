class Solution:
    def findCheapestPrice(self, n: int, flights: list[list[int]], src: int, dst: int, k: int) -> int:
        prices = [float("inf")] * n
        prices[src] = 0

        for _ in range(k + 1):
            tmpPrices = prices.copy()
            for s, d, p in flights: # s: source, d: destination, p: price
                if prices[s] == float("inf"):
                    continue
                if prices[s] + p < tmpPrices[d]:
                    tmpPrices[d] = prices[s] + p
            prices = tmpPrices
        
        return -1 if prices[dst] == float("inf") else prices[dst]


if __name__ == "__main__":
    n = 4
    flights = [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
    src = 0
    dst = 3
    k = 1
    print("Input: n = {}, flights = {}, src = {}, dst = {}, k = {}".format(n, flights, src, dst, k))
    print("Output: {}".format(Solution().findCheapestPrice(n, flights, src, dst, k)))