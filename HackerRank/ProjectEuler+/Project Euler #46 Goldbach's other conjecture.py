MAXN = int(5e5) + 1
is_prime = [True for _ in range(MAXN)]
is_prime[0] = is_prime[1] = False
for i in range(4, MAXN, 2):
	is_prime[i] = False
for i in range(3, MAXN, 2):
	if is_prime[i]:
		inc = i << 1
		for j in range(i + inc, MAXN, inc):
			is_prime[j] = False
for _ in range(int(input())):
	N = int(input())
	ans = 0
	for i in range(1, N):
		if i * i * 2 >= N:
			break
		if is_prime[N - i * i * 2]:
			ans += 1
	print(ans)