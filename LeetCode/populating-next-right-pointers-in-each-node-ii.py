# Definition for a  binary tree node
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree node
    # @return nothing
    def connect(self, root):
        if root is None:
            return
        node = root.next
        while node is not None:
            if node.left is not None:
                node = node.left
                break
            if node.right is not None:
                node = node.right
                break
            node = node.next
        if root.right is not None:
            root.right.next = node
        if root.left is not None:
            if root.right is None:
                root.left.next = node
            else:
                root.left.next = root.right
        self.connect(root.right)
        self.connect(root.left)
