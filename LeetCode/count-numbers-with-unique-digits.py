class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
        n = min(n, 10)
        dp = [1, 10]
        num, rem = 1, 9
        for i in range(2, 11):
            num *= rem
            rem -= 1
            dp.append(dp[i - 1] + 9 * num)
        return dp[n]
