class Solution:
    # @param s, a string
    # @return an integer
    def lengthOfLastWord(self, s):
        words = s.split(' ')
        words.reverse()
        for word in words:
            if len(word) > 0:
                return len(word)
        return 0
