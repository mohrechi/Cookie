# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param root, a tree node
    # @return nothing, do it in place
    def flatten(self, root):
        if root is None:
            return
        if root.left is not None:
            tail = self.flatten(root.left)
            temp = root.right
            root.right = root.left
            root.left = None
            tail.right = temp
            return self.flatten(root.right)
        if root.right is None:
            return root
        return self.flatten(root.right)
