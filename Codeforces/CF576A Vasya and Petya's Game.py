n = int(raw_input())
is_prime = [False, False] + [True] * n
ans = []
for i in xrange(2, n + 1):
    if is_prime[i]:
        ans.append(i)
        while ans[-1] * i <= n:
            ans.append(ans[-1] * i)
        for j in xrange(i + i, n + 1, i):
            is_prime[j] = False
print len(ans)
print ' '.join(map(str, ans))
