class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        preMap = {i : [] for i in range(numCourses)}
        for crs, pre in prerequisites:
            preMap[crs].append(pre)
        visitedSet = set()

        def dfs(crs):
            if crs in visitedSet:
                return False
            if preMap[crs] == []:
                return True

            visitedSet.add(crs)
            for pre in preMap[crs]:
                if not dfs(pre):
                    return False
            visitedSet.remove(crs)
            preMap[crs] = []
            return True

        for crs in range(numCourses):
            if not dfs(crs):
                return False
        return True


if __name__ == "__main__":
    numCourses = 2
    prerequisites = [[1, 0], [0, 1]]
    print('numCourses = {}, prerequisites = {}'.format(numCourses, prerequisites))
    print('Solution: {}'.format(Solution().canFinish(numCourses, prerequisites)))