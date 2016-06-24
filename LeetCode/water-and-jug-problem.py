from fractions import gcd

class Solution(object):
    def canMeasureWater(self, x, y, z):
        if z > x and z > y:
            return False
        return z % gcd(x, y) == 0
