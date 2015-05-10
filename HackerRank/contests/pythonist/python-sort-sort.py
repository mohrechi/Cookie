# Python 3
n, m = map(int, input().split(' '))
data = [list(map(int, input().split(' '))) for _ in range(n)]
k = int(input())
data = sorted(data, key=lambda x: x[k])
for d in data:
	print(' '.join(map(str, d)))