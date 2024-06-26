class Solution:
    @staticmethod
    def generateParenthesis(n: int) -> list[str]:
        stack = []
        result = []

        def backtrack(openN: int, closedN: int):
            if openN == closedN == n:
                result.append("".join(stack))
                return 
            
            if openN < n:
                stack.append("(")
                backtrack(openN+1, closedN)
                stack.pop()

            if closedN < openN:
                stack.append(")")
                backtrack(openN, closedN+1)
                stack.pop()

        backtrack(0, 0)
        return result


if __name__ == "__main__":
    print(Solution.generateParenthesis(3))