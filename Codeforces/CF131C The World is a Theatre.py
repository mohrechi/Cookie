fact = [1 for _ in range(31)]
for i in xrange(1, len(fact)): fact[i] = fact[i - 1] * i
def comb(n, m): return fact[n] / fact[m] / fact[n - m]
n, m, t = map(int, raw_input().split(' '))
ans = 0
for i in range(4, n + 1):
    for j in range(1, m + 1):
        if i + j == t:
            ans += comb(n, i) * comb(m, j)
print ans
