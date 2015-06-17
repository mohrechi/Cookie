N = int(input())
ans = 0
for i in range(2, 548835):
	t = i
	s = 0
	while t > 0:
		s += (t % 10) ** N
		t //= 10
		if s > i:
			break
	if s == i:
		ans += i
print(ans)