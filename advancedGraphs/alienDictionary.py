class Solution:
    def foreignDictionary(self, words: list[str]) -> str:
        adj = {c: [] for w in words for c in w}

        for i in range(len(words) - 1):
            w1, w2 = words[i], words[i + 1]
            minLen = min(len(w1), len(w2))
            if (len(w1) > len(w2)) and (w1[:minLen] == w2[:minLen]):
                return ""
            for j in range(minLen):
                if w1[j] != w2[j]:
                    adj[w1[j]].append(w2[j])
                    break
        visit = {} # False = visited, True = current path
        res = []

        def dfs(c):
            if c in visit:
                return visit[c]
            
            visit[c] = True
            for nei in adj[c]:
                if dfs(nei): 
                    return True
            visit[c] = False
            res.append(c)

        for c in adj:
            if dfs(c):
                return ""
        res.reverse()
        return "".join(res)


if __name__ == '__main__':
    Input = ["hrn","hrf","er","enn","rfnn"]
    print('Input : {}'.format(Input))
    print('Solution : {}'.format(Solution().foreignDictionary(Input)))