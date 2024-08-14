import heapq


class MedianFinder:

    def __init__(self):
        pass        

    def addNum(self, num: int) -> None:
        pass

    def findMedian(self) -> float:
        pass



if __name__ == '__main__':
    medianFinder = MedianFinder()
    medianFinder.addNum(1);    # arr = [1]
    medianFinder.addNum(2);    # arr = [1, 2]
    medianFinder.findMedian(); # return 1.5 (i.e., (1 + 2) / 2)
    medianFinder.addNum(3);    # arr[1, 2, 3]
    medianFinder.findMedian(); # return 2.0