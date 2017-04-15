b, q, l, m = map(int, raw_input().split(' '))
a = set(map(int, raw_input().split(' ')))

if abs(b) > l:
    print 0
elif b == 0:
    if b in a:
        print 0
    else:
        print 'inf'
elif q == 0:
    if 0 not in a:
        print 'inf'
    elif b in a:
        print 0
    else:
        print 1
elif q == 1:
    if b in a:
        print 0
    else:
        print 'inf'
elif q == -1:
    if b in a and -b in a:
        print 0
    else:
        print 'inf'
else:
    ans = 0
    while abs(b) <= l:
        if b not in a:
            ans += 1
        b *= q
    print ans
