s = raw_input()
if len(s) % 2 == 1:
    print -1
    exit(0)
d = ['L', 'R', 'U', 'D']
c = map(lambda c: sum(map(lambda x: x == c, s)), d)
ans = 0
if (c[0] + c[1]) % 2 == 1:
    ans = 1
    if c[0] > c[1]:
        c[0] -= 1
    else:
        c[1] -= 1
    if c[2] > c[3]:
        c[2] -= 1
    else:
        c[3] -= 1
ans += abs(c[0] - c[1]) / 2
ans += abs(c[2] - c[3]) / 2
print ans
