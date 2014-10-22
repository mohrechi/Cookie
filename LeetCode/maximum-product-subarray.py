class Solution:
    # @param A, a list of integers
    # @return an integer
    def maxProduct(self, A):
        return max(self.acc(A), self.acc(A[::-1]))
        
    def acc(self, A):
        temp = 1
        ret = A[0]
        for a in A:
            temp = temp * a
            ret = max(ret, temp)
            if temp == 0:
                temp = 1
        return ret