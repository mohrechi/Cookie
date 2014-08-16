class Solution:
    # @return a boolean
    def isPalindrome(self, x):
        if x < 0:
            return False
        y = 0
        tx = x
        while tx > 0:
            y = y * 10 + tx % 10
            tx /= 10
        return x == y
