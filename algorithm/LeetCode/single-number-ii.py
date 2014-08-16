class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        one = 0
        two = 0
        three = 0
        for a in A:
            two |= one & a
            one ^= a
            three = one & two
            one &= ~three
            two &= ~three
        return one
