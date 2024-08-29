class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: list[str]) -> int:
        return 1
    

if __name__ == "__main__":
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log","cog"]
    print("Input: beginWord = {}, endWord = {}, wordList = {}".format(beginWord, endWord, wordList))
    print("Solution: {}".format(Solution().ladderLength(beginWord, endWord, wordList)))