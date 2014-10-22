class Solution:
    # @param num, a list of integer
    # @return an integer
    def findMin(self, num):
        if len(num) == 1:
            return num[0]
        l = 0
        r = len(num) - 1
        while l <= r:
            if num[l] == num[r]:
                l = l + 1
            elif num[l] < num[r]:
                return num[l]
            else:
                m = (l + r) // 2
                if num[l] <= num[m]:
                    l = m + 1
                else:
                    r = m
        return num[r]