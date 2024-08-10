from trees.btf import *


class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        pass


if __name__ == '__main__':
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    print("Input:")
    btf(root)
    print("Sulution:")
    print(Solution().isBalanced(root))