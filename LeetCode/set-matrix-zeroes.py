class Solution:
    # @param matrix, a list of lists of integers
    # RETURN NOTHING, MODIFY matrix IN PLACE.
    def setZeroes(self, matrix):
        n = len(matrix)
        if n == 0:
            return
        m = len(matrix[0])
        firstRow = False
        firstCol = False
        row = [False for _ in range(n)]
        col = [False for _ in range(m)]
        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    row[i] = True
                    col[j] = True
        for i in range(n):
            if row[i]:
                for j in range(m):
                    matrix[i][j] = 0
        for j in range(m):
            if col[j]:
                for i in range(n):
                    matrix[i][j] = 0
