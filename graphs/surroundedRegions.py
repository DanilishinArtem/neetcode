from collections import deque

class Solution:
    def solve(self, board: list[list[str]]) -> None:
        rows, cols = len(board), len(board[0])
        def bfs(r, c):
            q = deque()
            q.append((r, c))
            while q:
                r, c = q.popleft()
                for nr, nc in ((r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)):
                    if nr < 0 or nr == rows or nc < 0 or nc == cols or board[nr][nc] != "O":
                        continue
                    board[nr][nc] = "*"
                    q.append((nr, nc))

        for r in [0, rows - 1]:
            for c in range(cols):
                if board[r][c] == "O":
                    board[r][c] = "*"
                    bfs(r, c)

        for r in range(rows):
            for c in [0, cols - 1]:
                if board[r][c] == "O": 
                    board[r][c] = "*"
                    bfs(r, c)

        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "O":
                    board[r][c] = "X"
                if board[r][c] == "*":
                    board[r][c] = "O"

    def solve_neetCode(self, board: list[list[str]]) -> None:
        rows, cols = len(board), len(board[0])
        def dfs(r,c):
            if r < 0 or c < 0 or r == rows or c == cols or board[r][c] != "O":
                return
            board[r][c] = "*"
            dfs(r+1,c)
            dfs(r-1,c)
            dfs(r,c+1)
            dfs(r,c-1)

        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "O" and (r in [0,rows-1] or c in [0,cols-1]):
                    dfs(r,c)

        for r in range(rows):
            for c in range(cols):
                if board[r][c] == "O":
                    board[r][c] = "X"
                if board[r][c] == "*":
                    board[r][c] = "O"


def print_board(board):
    for i in range(len(board)):
        print("{}".format(board[i]))

if __name__ == "__main__":
    board = [["X", "X", "X", "X"], ["X", "O", "O", "X"], ["X", "X", "O", "X"], ["X", "O", "X", "X"]]
    print("Source board")
    print_board(board)
    print("Changed board")
    Solution().solve_neetCode(board)
    print_board(board)