class Solution(object):
    def largestDivisibleSubset(self, nums):
        n = len(nums)
        if n == 0:
            return []
        nums.sort()
        pre = [-1] * n
        maxLen = [1] * n
        for i in xrange(1, n):
            for j in xrange(i):
                if nums[i] % nums[j] == 0:
                    if maxLen[j] + 1 > maxLen[i]:
                        maxLen[i] = maxLen[j] + 1
                        pre[i] = j
        maxPos = 0
        for i in xrange(1, n):
            if maxLen[i] > maxLen[maxPos]:
                maxPos = i
        sub = []
        while maxPos != -1:
            sub.append(nums[maxPos])
            maxPos = pre[maxPos]
        return sub
