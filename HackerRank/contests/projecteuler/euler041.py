from itertools import permutations

MAXP = int(1e5)
is_prime = [True for _ in range(MAXP)]
for i in range(4, MAXP, 2):
	is_prime[i] = False
primes = [2]
for i in range(3, MAXP, 2):
	if is_prime[i]:
		primes.append(i)
		inc = i << 1
		for j in range(i + inc, MAXP, inc):
			is_prime[j] = False
def check_prime(t):
	for p in primes:
		if p >= t:
			break
		if t % p == 0:
			return False
	return True
valid_nums = [-1]
for i in range(2, 10):
	for p in permutations([j for j in range(1, i + 1)]):
		t = 0
		for i in p:
			t = t * 10 + i
		if check_prime(t):
			valid_nums.append(t)
valid_nums.append(int(1e11))
for _ in range(int(input())):
	N = int(input())
	for i in range(len(valid_nums)):
		if valid_nums[i] > N:
			print(valid_nums[i - 1])
			break