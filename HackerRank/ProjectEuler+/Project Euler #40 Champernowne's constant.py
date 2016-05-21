from functools import reduce

def get_digit(x):
	x = int(x) - 1
	d = 0
	while True:
		s = 9 * (10 ** d) * (d + 1)
		if x <= s:
			break
		x -= s
		d += 1
	num = x // (d + 1)
	x -= (d + 1) * num
	num += 10 ** d
	return int(str(num)[x])
[print(reduce(lambda x, y: x * y, map(get_digit, input().split(' ')))) for _ in range(int(input()))]
	