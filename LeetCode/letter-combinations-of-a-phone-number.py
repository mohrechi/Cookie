class Solution:
    # @return a list of strings, [s1, s2]
    def letterCombinations(self, digits):
        self.letters = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'}
        self.results = []
        self.path = ''
        self.dfs(0, digits)
        return self.results
    def dfs(self, index, digits):
        if index == len(digits):
            self.results.append(self.path[:])
            return
        for l in self.letters[digits[index]]:
            self.path += l
            self.dfs(index + 1, digits)
            self.path = self.path[:-1]
