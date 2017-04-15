s = raw_input()
a = eval(s)
s = str(a)
code = ''
for c in s:
    code += '>' + '+' * ord(c) + '.'
print code
