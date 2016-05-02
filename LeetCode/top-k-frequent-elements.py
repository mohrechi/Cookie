from collections import Counter

class Solution(object):
    def topKFrequent(self, nums, k):
        return [x[0] for x in Counter(nums).most_common(k)]
