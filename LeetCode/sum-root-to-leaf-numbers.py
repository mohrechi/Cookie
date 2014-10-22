# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return an integer
    def sumNumbers(self, root):
        self.total = 0
        self.dfs(root, 0)
        return self.total
    def dfs(self, node, num):
        if node is None:
            return
        num = num * 10 + node.val
        if node.left is None and node.right is None:
            self.total += num
            return
        self.dfs(node.left, num)
        self.dfs(node.right, num)
