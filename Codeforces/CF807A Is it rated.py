n = input()
a, b = [], []
for _ in xrange(n):
    x, y = map(int, raw_input().split())
    a.append(x)
    b.append(y)
if a != b:
    print 'rated'
else:
    if a == sorted(a, reverse=True):
        print 'maybe'
    else:
        print 'unrated'
