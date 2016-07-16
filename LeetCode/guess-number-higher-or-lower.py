class Solution(object):
    def guessNumber(self, n):
        l, r = 1, n
        while True:
            mid = (l + r) >> 1
            g = guess(mid)
            if g == 0:
                return mid
            if g == 1:
                l = mid + 1
            else:
                r = mid - 1
