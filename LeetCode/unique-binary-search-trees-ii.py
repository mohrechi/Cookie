# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @return a list of tree node
    def generateTrees(self, n):
        return self.generate(1, n)
    def generate(self, l, r):
        if l > r:
            return [None]
        trees = []
        for k in range(l, r + 1):
            left = self.generate(l, k - 1)
            right = self.generate(k + 1, r)
            for lc in left:
                for rc in right:
                    head = TreeNode(k)
                    head.left = lc
                    head.right = rc
                    trees.append(head)
        return trees
