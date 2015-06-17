MAXN = int(1e6)
is_prime = [True for _ in range(MAXN)]
is_prime[0] = is_prime[1] = False
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
	if p < 10:
		continue
	if p >= N:
		break
	flag = True
	s = str(p)
	while len(s) > 1:
		s = s[1:]
		if not is_prime[int(s)]:
			flag = False
			break
	if flag:
		s = str(p)
		while len(s) > 1:
			s = s[:-1]
			if not is_prime[int(s)]:
				flag = False
				break
	if flag:
		ans += p
print(ans)