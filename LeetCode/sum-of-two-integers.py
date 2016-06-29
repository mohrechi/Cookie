class Solution(object):
    def getSum(self, a, b):
        if b == 0:
            return a
        return self.getSum(a ^ b, (a & b) << 1)
