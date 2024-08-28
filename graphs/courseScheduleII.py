class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        prereq = {c : [] for c in range(numCourses)}
        for crs, pre in prerequisites:
            prereq[crs].append(pre)

        # a course has 3 possible states:
            # visited -> crs has beed added to output
            # visiting -> crs is being added to output
            # unvisited -> crs has not been added to output or cycle
        output = []
        visit, cycle = set(), set()
        def dfs(crs):
            if crs in cycle:
                return False
            if crs in visit:
                return True
            
            cycle.add(crs)
            for pre in prereq[crs]:
                if dfs(pre) == False:
                    return False
            cycle.remove(crs)
            visit.add(crs)
            output.append(crs)
            return True
        
        for c in range(numCourses):
            if dfs(c) == False:
                return []
        return output


if __name__ == "__main__":
    numCourses = 2
    # prerequisites = [[5,0],[4,0],[0,1],[0,2],[1,3],[3,2]]
    prerequisites = [[1,0]]
    print('numCourses = {}, prerequisites = {}'.format(numCourses, prerequisites))
    print('Solution: {}'.format(Solution().findOrder(numCourses, prerequisites)))