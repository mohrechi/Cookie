def format(h, m):
    s = ''
    if h < 10: s += '0'
    s += str(h)
    s += ':'
    if m < 10: s += '0'
    s += str(m)
    return s

t = raw_input()[:5]
h = int(t[0:2])
m = int(t[3:5])
while True:
    m += 1
    if m == 60:
        m = 0
        h += 1
        if h == 24:
            h = 0
    s = format(h, m)
    if s == s[::-1]: break
print s
