class Solution:
    # @param obstacleGrid, a list of lists of integers
    # @return an integer
    def uniquePathsWithObstacles(self, obstacleGrid):
        m = len(obstacleGrid)
        if m == 0:
            return 0
        n = len(obstacleGrid[0])
        if n == 0:
            return 0
        if obstacleGrid[0][0] == 1:
            return 0
        path = [[0 for _ in range(n)] for _ in range(m)]
        path[0][0] = 1
        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 0:
                    if i > 0:
                        path[i][j] += path[i - 1][j]
                    if j > 0:
                        path[i][j] += path[i][j - 1]
        return path[m - 1][n - 1]
