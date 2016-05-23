class Solution(object):
    def intersect(self, nums1, nums2):
        nums1.sort()
        nums2.sort()
        inter = []
        n, m = len(nums1), len(nums2)
        i, j = 0, 0
        while i < n and j < m:
            if nums1[i] == nums2[j]:
                inter.append(nums1[i])
                i += 1
                j += 1
            elif nums1[i] < nums2[j]:
                i += 1
            else:
                j += 1
        return inter
