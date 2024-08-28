from collections import deque

class Solution:
    def validTree(self, n: int, edges: list[list[int]]) -> bool:
        if not n:
            return True
        
        adj = {i : [] for i in range(n)}
        for n1, n2 in edges:
            adj[n1].append(n2)
            adj[n2].append(n1)
        
        visited = set()
        def dfs(i, prev):
            if i in visited:
                return False
            visited.add(i)
            for j in adj[i]:
                if j == prev:
                    continue
                if not dfs(j, i):
                    return False
            return True
        
        return dfs(0, -1) and n == len(visited)
                


if __name__ == "__main__":
    n = 4
    edges = [[0,1],[2,3]]
    print('Input: n = {}, edges = {}'.format(n, edges))
    print('Solution: {}'.format(Solution().validTree(n, edges)))