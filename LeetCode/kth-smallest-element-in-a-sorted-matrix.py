class Solution(object):
    def kthSmallest(self, matrix, k):
        n = len(matrix)
        l, r = matrix[0][0], matrix[n - 1][n - 1]
        ans = l
        while l <= r:
            mid = (l + r) / 2
            num = 0
            for i in xrange(n):
                if mid > matrix[i][n - 1]:
                    num += n
                elif mid > matrix[i][0]:
                    ll, rr = 0, n - 1
                    max_num = 0
                    while ll <= rr:
                        mm = (ll + rr) / 2
                        if matrix[i][mm] < mid:
                            max_num = max(max_num, mm)
                            ll = mm + 1
                        else:
                            rr = mm - 1
                    num += max_num + 1
            if num < k:
                ans = max(ans, mid)
                l = mid + 1
            else:
                r = mid - 1
        return ans
