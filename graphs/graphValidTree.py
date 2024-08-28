class Solution:
    def validTree(self, n: int, edges: list[list[int]]) -> bool:
        pass


if __name__ == "__main__":
    n = 5
    edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
    print('Input: n = {}, edges = {}'.format(n, edges))
    print('Solution: {}'.format(Solution().validTree(n, edges)))