class Solution:
    # @return a string
    def intToRoman(self, num):
        romans = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        roman = ''
        index = 0
        while num > 0:
            while num >= values[index]:
                roman += romans[index]
                num -= values[index]
            index += 1
        return roman
