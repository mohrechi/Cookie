import sys

isp = {'+':3, '-':3, '*':5, '/':5, '^':7, '(':1}
icp = {'$':0, '+':2, '-':2, '*':4, '/':4, '^':6, '(':8, ')':1}

def transform(s):
    s += '$'
    stack = []
    for c in s:
        if c.isalpha():
            sys.stdout.write(c)
            continue
        ic = icp[c]
        while len(stack) and ic < isp[stack[-1]]:
            sys.stdout.write(stack[-1])
            del(stack[-1])
        if len(stack) == 0 or ic > isp[stack[-1]]:
            stack.append(c)
        else:
            del(stack[-1])
    sys.stdout.write('\n')

for i in range(int(input(''))):
    transform(input(''))

