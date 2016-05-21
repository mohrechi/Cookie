MAXN = 10000
is_prime = [True for _ in range(MAXN)]
for i in range(4, MAXN, 2):
	is_prime[i] = False
for i in range(3, MAXN, 2):
	inc = i << 1
	for j in range(i + inc, MAXN, inc):
		is_prime[j] = False
prime = [2]
for i in range(3, MAXN, 2):
	if is_prime[i]:
		prime.append(i)
N = int(input())
la = 0
lb = 0
longest = -1
def check_prime(x):
	if x < 2:
		return False
	if x < MAXN:
		return is_prime[x]
	for p in prime:
		if x % p == 0:
			return False
	return True
for a in range(-N, N + 1):
	for b in prime:
		if b > N:
			break
		for n in range(10000):
			val = n * n + a * n + b
			if not check_prime(val):
				break
		if n > longest:
			longest = n
			la = a
			lb = b
print(str(la) + ' ' + str(lb))			
		 