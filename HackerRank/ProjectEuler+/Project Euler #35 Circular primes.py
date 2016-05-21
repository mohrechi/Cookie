MAXN = int(1e6)
is_prime = [True for _ in range(MAXN)]
for i in range(4, MAXN, 2):
	is_prime[i] = False
for i in range(3, MAXN, 2):
	inc = i << 1
	for j in range(i + inc, MAXN, inc):
		is_prime[j] = False
primes = [2]
for i in range(3, MAXN, 2):
	if is_prime[i]:
		primes.append(i)
ans = 0
N = int(input())
for p in primes:
	if p >= N:
		break
	l = len(str(p))
	h = 10 ** (l - 1)
	flag = True
	t = p
	for i in range(1, l):
		t = t // 10 + t % 10 * h
		if not is_prime[t]:
			flag = False
			break
	if flag:
		ans += p
print(ans)