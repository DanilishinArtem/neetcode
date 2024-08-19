class Solution:
    def mergeTriplets(self, triplets: list[list[int]], target: list[int]) -> bool:
        good = set()

        for t in triplets:
            if t[0] > target[0] or t[1] > target[1] or t[2] > target[2]:
                continue
            for i, v in enumerate(t):
                if v == target[i]:
                    good.add(i)
        return len(good) == 3



if __name__ == "__main__":
    triplets = [[2,5,3],[1,8,4],[1,7,5]]
    target = [2,7,5]
    print("Input:")
    print("triplets = " + str(triplets))
    print("target = " + str(target))
    print("Solution:")
    print(Solution().mergeTriplets(triplets, target))