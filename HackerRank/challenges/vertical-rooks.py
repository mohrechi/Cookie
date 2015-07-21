t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    x = [int(raw_input()) for _ in xrange(n)]
    y = [int(raw_input()) for _ in xrange(n)]
    xor = 0
    for i in xrange(n):
        xor ^= abs(x[i] - y[i]) - 1
    if xor == 0:
        print 'player-1'
    else:
        print 'player-2'
