N = int(input())
ans = []
visit = [False for _ in range(N + 1)]
def gen(d, s):
	global ans
	if d == N:
		for i in range(1, N):
			for j in range(1, N - i):
				if N - i - j >= i + j - 1:
					k = N - i - j
					a = int(s[:i])
					b = int(s[i:i+j])
					if a < b:
						c = int(s[i+j:])
						if a * b == c:
							if c not in ans:
								ans.append(c)
	else:
		for i in range(1, N + 1):
			if not visit[i]:
				visit[i] = True
				gen(d + 1, s + chr(i + ord('0')))
				visit[i] = False
gen(0, "")
print(sum(ans))