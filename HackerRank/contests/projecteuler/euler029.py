N = int(input())
nums = []
app = set()
for i in range(1, 18):
	nums.append(0)
	for j in range(i << 1, i * N + 1, i):
		if j not in app:
			app.add(j)
			nums[-1] += 1
visit = [False for _ in range(N + 1)]
ans = 0
for i in range(2, N + 1):
	if not visit[i]:
		j = i
		d = 0
		while j <= N:
			ans += nums[d]
			d += 1
			visit[j] = True
			j *= i
print(ans)
			