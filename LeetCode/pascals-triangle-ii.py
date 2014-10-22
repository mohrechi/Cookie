class Solution:
    # @return a list of integers
    def getRow(self, rowIndex):
        tri = [[], []]
        curr = 0
        prev = 1
        for i in range(rowIndex + 1):
            curr, prev = prev, curr
            tri[curr] = [0 for _ in range(i + 1)]
            for j in range(i + 1):
                if j in [0, i]:
                    tri[curr][j] = 1
                else:
                    tri[curr][j] = tri[prev][j - 1] + tri[prev][j]
        return tri[curr]
