MAXN = int(2e5 + 5)

n = [2 * MAXN for _ in xrange(MAXN)]

def get(c, p, s, i):
    k = p - s + c
    if k < MAXN:
        n[k] = min(n[k], p)
        for j in range(i, MAXN // p * 2):
            get(c + 1, p * j, s + j, j)

x = input()
get(1, 1, 1, 2)
print sum(set(n[2:x+1]))
