n = int(raw_input())
a = [0] * n
for i in xrange(n):
    a[i] = int(raw_input())
a.sort()
ans = 0
for i in xrange(n):
    ans += a[i] * a[n - i - 1]
print ans % 10007
