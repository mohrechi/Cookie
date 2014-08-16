class Solution:
    # @param triangle, a list of lists of integers
    # @return an integer
    def minimumTotal(self, triangle):
        for i in range(1, len(triangle)):
            for j in range(0, len(triangle[i])):
                path = 1e10
                if j < len(triangle[i]) - 1:
                    path = triangle[i - 1][j]
                if j > 0:
                    path = min(path, triangle[i - 1][j - 1])
                triangle[i][j] += path
        return min(triangle[-1])
