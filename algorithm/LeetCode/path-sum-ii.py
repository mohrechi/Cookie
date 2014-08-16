# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @param sum, an integer
    # @return a list of lists of integers
    def pathSum(self, root, sum):
        self.ret = []
        self.path = []
        self.dfs(root, sum)
        return self.ret
    def dfs(self, root, sum):
        if root is None:
            return
        self.path.append(root.val)
        if sum == root.val and root.left is None and root.right is None:
            self.ret.append(self.path[:])
        self.dfs(root.left, sum - root.val)
        self.dfs(root.right, sum - root.val)
        del self.path[-1]
