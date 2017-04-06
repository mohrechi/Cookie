MAXN = 1000000
is_prime = [True] * MAXN
primes = [0]
for i in xrange(2, MAXN):
    if is_prime[i]:
        for j in xrange(i + i, MAXN, i):
            is_prime[j] = False
for i in xrange(2, MAXN):
    if is_prime[i]:
        r = int(str(i)[::-1])
        if is_prime[r] and i != r:
            primes.append(i)
d = input()
print primes[d]
