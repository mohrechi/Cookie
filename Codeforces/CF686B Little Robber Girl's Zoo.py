n = int(raw_input())
a = map(int, raw_input().split(' '))
for i in xrange(n):
    for j in xrange(0, n - i - 1):
        if a[j] > a[j + 1]:
            a[j], a[j + 1] = a[j + 1], a[j]
            print j + 1, j + 2
