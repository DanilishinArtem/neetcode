class UnionFind:
    def __init__(self):
        self.f = {}

    def findParent(self, x):
        y = self.f.get(x, x)
        if x != y:
            y = self.f[x] = self.findParent(y)
        return y

    def union(self, x, y):
        self.f[self.findParent(x)] = self.findParent(y)


class Solution:
    def countComponents(self, n: int, edges: list[list[int]]) -> int:
        dsu = UnionFind()
        for a, b in edges:
            dsu.union(a, b)
        return len(set(dsu.findParent(x) for x in range(n)))
    

if __name__ == "__main__":
    n = 5
    edges = [[0,1], [1,2], [2,3], [4,5]]
    print('Input: n = {}, edges = {}'.format(n, edges))
    print('Solution: {}'.format(Solution().countComponents(n, edges)))