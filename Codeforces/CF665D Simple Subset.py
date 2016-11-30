is_prime = [False, False] + [True] * 2000000
for i in xrange(2, 2000001):
    if is_prime[i]:
        for j in xrange(i + i, 2000001, i):
            is_prime[j] = False

n = int(raw_input())
a = sorted(map(int, raw_input().split(' ')))
ans = [a[0]]
for i in xrange(n):
    for j in xrange(i + 1, n):
        if is_prime[a[i] + a[j]]:
            ans = [a[i], a[j]]
cnt1 = len(filter(lambda x: x == 1, a))
if cnt1 > 0:
    if cnt1 > 2:
        ans = [1] * cnt1
    for x in a:
        if x != 1 and is_prime[x + 1]:
            ans = [x] + [1] * cnt1
print len(ans)
print ' '.join(map(str, ans))
