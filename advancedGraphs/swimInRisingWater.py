import heapq

class Solution:
    def swimInWater(self, grid: list[list[int]]) -> int:
        N = len(grid)
        visited = set()
        minH = [[grid[0][0], 0, 0]] # (time/max-height, row, col)
        directions = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        while minH:
            time, row, col = heapq.heappop(minH)
            if row == N - 1 and col == N - 1:
                return time
            for dr, dc in directions:
                neiRow = row + dr
                neiCol = col + dc
                if neiRow < 0 or neiRow == N or neiCol < 0 or neiCol == N or (neiRow, neiCol) in visited:
                    continue
                visited.add((neiRow, neiCol))
                heapq.heappush(minH, [max(time, grid[neiRow][neiCol]), neiRow, neiCol])
            



if __name__ == "__main__":
    grid = [[0,2],[1,3]]
    print("Input: {}".format(grid))
    print("Solution: {}".format(Solution().swimInWater(grid)))