from collections import deque


class Solution:
    def islandsAndTreasure(self, rooms: list[list[int]]) -> None:
        rows, cols = len(rooms), len(rooms[0])
        visit = set()
        q = deque()

        def addRoom(r, c):
            if r < 0 or c < 0 or r == rows or c == cols or rooms[r][c] == -1 or (r, c) in visit:
                return
            visit.add((r, c))
            q.append((r, c))
        
        for r in range(rows):
            for c in range(cols):
                if rooms[r][c] == 0:
                    q.append((r, c))
                    visit.add((r, c))

        dist = 0
        while q:
            for i in range(len(q)):
                r, c = q.popleft()
                rooms[r][c] = dist
                addRoom(r + 1, c)
                addRoom(r - 1, c)
                addRoom(r, c + 1)
                addRoom(r, c - 1)
            dist += 1


if __name__ == "__main__":
    rooms = [[2147483647,-1,0,2147483647],
             [2147483647,2147483647,2147483647,-1],
             [2147483647,-1,2147483647,-1],
             [0,-1,2147483647,2147483647]]
    print("Input: {}".format(rooms))
    Solution().islandsAndTreasure(rooms=rooms)
    print("Output: {}".format(rooms))