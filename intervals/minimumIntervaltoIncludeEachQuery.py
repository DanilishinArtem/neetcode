import heapq


class Solution:
    def minInterval(self, intervals: list[list[int]], queries: list[int]) -> list[int]:
        intervals.sort()
        minHeap = []
        res, i = {}, 0
        for q in sorted(queries):
            while i < len(intervals) and intervals[i][0] <= q:
                l, r = intervals[i]
                heapq.heappush(minHeap, (r - l + 1, r))
                i += 1
            while minHeap and minHeap[0][1] < q:
                heapq.heappop(minHeap)
            res[q] = minHeap[0][0] if minHeap else -1
        return [res[q] for q in queries]


if __name__ == "__main__":
    print("Input:")
    intervals = [[2,3],[2,5],[1,8],[20,25]]
    queries = [2,19,5,22]
    print("intervals = " + str(intervals))
    print("queries = " + str(queries))
    print("Solution:")
    print(Solution().minInterval(intervals, queries))