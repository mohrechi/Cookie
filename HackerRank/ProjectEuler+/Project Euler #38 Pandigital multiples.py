N, K = map(int, input().split(' '))
for i in range(2, N):
	s = ''
	for j in range(1, 10):
		s += str(i * j)
		if len(s) >= K:
			break;
	if len(s) == K:
		v = [False for _ in range(10)]
		v[0] = True
		if K == 8:
			v[9] = True
		flag = True
		for c in s:
			if v[ord(c) - ord('0')]:
				flag = False
				break
			else:
				v[ord(c) - ord('0')] = True
		if flag:
			print(i)