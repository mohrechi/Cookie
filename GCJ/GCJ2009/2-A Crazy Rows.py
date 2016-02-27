t = input()
for k in xrange(t):
    n = input()
    b = []
    for _ in xrange(n):
        s = raw_input()[::-1]
        cnt = 0
        for c in s:
            if c != '0':
                break
            cnt += 1
        b.append(cnt)
    cnt = 0
    for i in xrange(n):
        for j in xrange(i, n):
            if b[j] >= n - i - 1:
                if i != j:
                    while j > i:
                        b[j - 1], b[j] = b[j], b[j - 1]
                        j -= 1
                        cnt += 1
                break
    print "Case #" + str(k + 1) + ": " + str(cnt)
