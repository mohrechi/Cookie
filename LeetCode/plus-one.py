class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        carry = 1
        digits.reverse()
        for i in range(len(digits)):
            digits[i] += carry
            if digits[i] >= 10:
                digits[i] = 0
            else:
                carry = 0
                break
        if carry:
            digits += [1]
        digits.reverse()
        return digits