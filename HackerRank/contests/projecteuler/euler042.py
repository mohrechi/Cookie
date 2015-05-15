import math

for _ in range(int(input())):
	t = int(input()) * 2
	i = int(math.floor(math.sqrt(t)))
	ans = -1
	while i * (i + 1) <= t:
		if i * (i + 1) == t:
			ans = i
			break
		i += 1
	print(ans)