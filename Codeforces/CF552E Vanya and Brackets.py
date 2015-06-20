s = raw_input()
ans = eval(s)
pre = [-1]
for i in range(len(s) + 1):
    if i == len(s) or s[i] == '*':
        for p in pre:
            ts = s[:p+1] + '(' + s[p+1:i] + ')' + s[i:]
            ans = max(ans, eval(ts))
        pre.append(i)
print ans
