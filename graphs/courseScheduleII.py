class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        pass


if __name__ == "__main__":
    numCourses = 2
    prerequisites = [[1,0]]
    print('numCourses = {}, prerequisites = {}'.format(numCourses, prerequisites))
    print('Solution: {}'.format(Solution().findOrder(numCourses, prerequisites)))