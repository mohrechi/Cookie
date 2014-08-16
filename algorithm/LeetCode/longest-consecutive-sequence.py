class Solution:
    # @param num, a list of integer
    # @return an integer
    def longestConsecutive(self, num):
        num.sort()
        ans = 1
        cur = 1
        for i in range(1, len(num)):
            if num[i] == num[i - 1] + 1:
                cur += 1
                ans = max(ans, cur)
            elif num[i] != num[i - 1]:
                cur = 1
        return ans
