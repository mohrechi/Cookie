class Solution(object):
    def superPow(self, a, b):
        return pow(a, reduce(lambda x, y: x * 10 + y, b, 0), 1337)
