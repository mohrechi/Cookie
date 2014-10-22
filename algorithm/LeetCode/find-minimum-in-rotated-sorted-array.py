class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        l = 0
        r = len(num) - 1
        ret = num[0]
        while l <= r:
            m = (l + r) // 2
            ret = min(ret, num[m])
            if num[0] <= num[m] and num[m] > num[-1]:
                l = m + 1
            else:
                r = m - 1
        return ret