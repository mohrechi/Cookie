s = raw_input()
a = s.count('H')
b = s.count('Q')
if b == 0:
    ans = True
else:
    m = int(b ** 0.5)
    if m * m != b and a % (m + 1) != 0:
        ans = False
    else:
        n = a / (m + 1)
        p = s.index('Q')
        if p % 2 == 1:
            ans = False
        else:
            src = s[p / 2:p / 2 + n + m]
            dst = ''
            for c in src:
                if c == 'H':
                    dst += 'H'
                else:
                    dst += src
            ans = dst == s
if ans:
    print 'Yes'
else:
    print 'No'
