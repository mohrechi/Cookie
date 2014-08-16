class Solution:
    # @param matrix, a list of lists of integers
    # @param target, an integer
    # @return a boolean
    def searchMatrix(self, matrix, target):
        n = len(matrix)
        if n == 0:
            return False
        m = len(matrix[0])
        if m == 0:
            return False
        l = 0
        r = n * m - 1
        while l <= r:
            mid = (l + r) >> 1
            x = mid / m
            y = mid % m
            if matrix[x][y] == target:
                return True
            if matrix[x][y] < target:
                l = mid + 1
            else:
                r = mid - 1
        return False
