t = input()
for i in range(t):
    n = input()
    x = sorted(map(int, raw_input().split(' ')))
    y = reversed(sorted(map(int, raw_input().split(' '))))
    z = zip(x, y)
    s = sum(map(lambda a: a[0]*a[1], z))
    print "Case #" + str(i + 1) + ": " + str(s)
