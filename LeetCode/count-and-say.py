class Solution:
    # @return a string
    def countAndSay(self, n):
        if n == 0:
            return ''
        prev = '1'
        next = ''
        while n > 1:
            cnt = 1
            for i in range(1, len(prev)):
                if prev[i] == prev[i - 1]:
                    cnt += 1
                else:
                    next += str(cnt)
                    next += prev[i - 1]
                    cnt = 1
            next += str(cnt)
            next += prev[-1]
            prev = next
            next = ''
            n -= 1
        return prev
