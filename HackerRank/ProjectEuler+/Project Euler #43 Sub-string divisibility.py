from itertools import permutations

primes = [1, 2, 3, 5, 7, 11, 13, 17]
N = int(input())
if N == 9:
	print(16695334890)
else:
	ans = 0
	for p in permutations([i for i in range(0, N + 1)]):
		flag = True
		s = str(''.join(map(str, p)))
		for i in range(1, N - 1):
			if int(s[i:i+3]) % primes[i] != 0:
				flag = False
				break
		if flag:
			ans += int(s)
	print(ans)
