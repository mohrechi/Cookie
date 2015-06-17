f = [3]
a = 1.0
b = 1.0
index = 2
while len(f) <= 5000:
	c = a + b
	index += 1
	if c > 10.0 - 1e-6:
		b /= 10.0
		c /= 10.0
		f.append(index)
	a, b = b, c
[print(f[int(input()) - 1]) for _ in range(int(input()))]
