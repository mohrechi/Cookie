class Solution:
    # @return a list of lists of integers
    def generate(self, numRows):
        tri = []
        for i in range(numRows):
            tri.append([])
            for j in range(i + 1):
                if j == 0 or j == i:
                    tri[i].append(1)
                else:
                    tri[i].append(tri[i - 1][j - 1] + tri[i - 1][j])
        return tri
