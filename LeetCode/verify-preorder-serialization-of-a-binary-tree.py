class Solution(object):
    def isValidSerialization(self, preorder):
        self.nodes = preorder.split(',')
        return self.traverse(0) == len(self.nodes)
        
    def traverse(self, idx):
        if idx >= len(self.nodes):
            return -1
        if self.nodes[idx] == '#':
            return idx + 1
        idx = self.traverse(idx + 1)
        if idx == -1:
            return -1
        return self.traverse(idx)
