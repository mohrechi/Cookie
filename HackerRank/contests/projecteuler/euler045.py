N, a, b = map(int, input().split(' '))

ans3 = [1, 210, 40755, 7906276, 1533776805, 297544793910, 57722156241751]
ans5 = [1, 40755, 1533776805, 57722156241751]

ans = []
if a == 3:
	for a in ans3:
		if a < N:
			ans.append(a)
else:
	for a in ans5:
		if a < N:
			ans.append(a)
for a in ans:
	print(a)
exit()

func = {3: lambda x: x * (x + 1) // 2,
		5: lambda x: x * (3 * x - 1) // 2,
		6: lambda x: x * (x * 2 - 1)}
sa = 1
sb = 1
fa = func[a]
fb = func[b]
va = fa(sa)
vb = fb(sb)
ans = []
while va < N and vb < N:
	if va == vb:
		ans.append(va)
		sa += 1
		sb += 1
		va = fa(sa)
		vb = fb(sb)
	elif va < vb:
		sa += 1
		va = fa(sa)
	else:
		sb += 1
		vb = fb(sb)
for a in ans:
	print(a)