class Solution:
    # @param an integer
    # @return a list of string
    def generateParenthesis(self, n):
        self.results = []
        self.dfs(n, n, '')
        return self.results
    def dfs(self, l, r, path):
        if l > r:
            return
        if l == 0 and r == 0:
            self.results.append(path)
            return
        if l > 0:
            self.dfs(l - 1, r, path + '(')
        if r > 0:
            self.dfs(l, r - 1, path + ')')
