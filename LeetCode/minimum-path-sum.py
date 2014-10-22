class Solution:
    # @param grid, a list of lists of integers
    # @return an integer
    def minPathSum(self, grid):
        n = len(grid)
        if n == 0:
            return 0
        m = len(grid[0])
        if m == 0:
            return 0
        for i in range(n):
            for j in range(m):
                if i == 0 and j == 0:
                    continue
                path = 1e100
                if i > 0:
                    path = min(path, grid[i - 1][j])
                if j > 0:
                    path = min(path, grid[i][j - 1])
                grid[i][j] += path
        return grid[n - 1][m - 1]
