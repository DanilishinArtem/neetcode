class Solution:
    def findItinerary(self, tickets: list[list[str]]) -> list[str]:
        adj = {src : [] for src, dest in tickets}
        tickets.sort()
        for src, dst in tickets:
            adj[src].append(dst)

        res = ["JFK"]
        def dfs(src):
            if len(res) == len(tickets) + 1:
                return True
            if src not in adj:
                return False
            temp = list(adj[src])
            for i, v in enumerate(temp):
                adj[src].pop(i)
                res.append(v)
                if dfs(v):
                    return True
                adj[src].insert(i, v)
                res.pop()
            return False
        
        dfs("JFK")
        return res


if __name__ == "__main__":
    tickets = [["HOU","JFK"],["SEA","JFK"],["JFK","SEA"],["JFK","HOU"]]
    print('Input: {}'.format(tickets))
    solution = Solution().findItinerary(tickets)
    print('Solution: {}'.format(solution))