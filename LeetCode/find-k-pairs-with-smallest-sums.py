class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        return heapq.nsmallest(k, ([u, v] for u in nums1 for v in nums2), key=sum)
