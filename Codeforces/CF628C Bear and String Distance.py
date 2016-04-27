n, k = map(int, raw_input().split(' '))
s = raw_input()
ss = ''
for c in s:
    p = ord(c) - ord('a')
    if k > 0:
        if p >= 13:
            r = min(p, k)
            ss += chr(p - r + ord('a'))
        else:
            r = min((25 - p), k)
            ss += chr(p + r + ord('a'))
        k -= r
    else:
        ss += c
if k > 0:
    print -1
else:
    print ss
