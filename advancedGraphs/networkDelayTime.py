from collections import defaultdict
import heapq

class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        edges = defaultdict(list)
        for u, v, w in times:
            edges[u].append((v, w))

        minHeap = [(0, k)]
        visit = set()
        t = 0
        while minHeap:
            w1, n1 = heapq.heappop(minHeap)
            if n1 in visit:
                continue
            visit.add(n1)
            t = max(t, w1)

            for n2, w2 in edges[n1]:
                if n2 not in visit:
                    heapq.heappush(minHeap, (w1 + w2, n2))
        
        return t if len(visit) == n else -1


if __name__ == "__main__":
    n = 4
    k = 2
    times = [[2, 1, 1], [2, 3, 1], [3, 4, 1]]
    print("Input: n = {}, k = {}, times = {}".format(n, k, times))
    print("Output: {}".format(Solution().networkDelayTime(times, n, k)))