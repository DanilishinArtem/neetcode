import heapq

class Solution:
    def minCostConnectPoints(self, points: list[list[int]]) -> int:
        N = len(points)
        adj = {i: [] for i in range(N)}
        for i in range(N):
            x1, y1 = points[i]
            for j in range(i + 1, N):
                x2, y2 = points[j]
                dist = abs(x1 - x2) + abs(y1 - y2)
                adj[i].append((dist, j))
                adj[j].append((dist, i))
        # Prim's
        res = 0
        visited = set()
        minHeap = [[0, 0]]
        while len(visited) < N:
            const, i = heapq.heappop(minHeap)
            if i in visited:
                continue
            res += const
            visited.add(i)
            for neiCost, nei in adj[i]:
                if nei not in visited:
                    heapq.heappush(minHeap, [neiCost, nei])
        return res


if __name__ == "__main__":
    points = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
    print("Input: {}".format(points))
    print("Solution: {}".format(Solution().minCostConnectPoints(points)))