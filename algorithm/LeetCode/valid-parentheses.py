class Solution:
    # @return a boolean
    def isValid(self, s):
        stack = []
        for c in s:
            flag = True
            if c == ')':
                if len(stack) > 0:
                    if stack[-1] == '(':
                        del stack[-1]
                        flag = False
            elif c == ']':
                if len(stack) > 0:
                    if stack[-1] == '[':
                        del stack[-1]
                        flag = False
            elif c == '}':
                if len(stack) > 0:
                    if stack[-1] == '{':
                        del stack[-1]
                        flag = False
            if flag:
                stack.append(c)
        return len(stack) == 0
