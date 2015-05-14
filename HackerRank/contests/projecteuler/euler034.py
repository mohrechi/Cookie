from math import factorial

ans = 0
fact = list(map(factorial, [i for i in range(11)]))
for i in range(10, int(input())):
	t = i
	s = 0
	while t > 0:
		s += fact[t % 10]
		t //= 10
	if s % i == 0:
		ans += i
print(ans)