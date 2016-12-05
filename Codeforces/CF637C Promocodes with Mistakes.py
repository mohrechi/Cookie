n = int(raw_input())
s = []
for _ in xrange(n):
    s.append(raw_input())
ans = 12
for i in xrange(n):
    for j in xrange(i + 1, n):
        ans = min(ans, sum(map(lambda (a, b): a != b, zip(s[i], s[j]))) - 1)
print ans // 2
