# Python 3
n = int(input())
l = len(bin(n)) - 2
for i in range(1, n + 1):
	print(' '.join(map(lambda x: ' ' * (l - len(x)) + x, [str(i), oct(i)[2:], hex(i)[2:].upper(), bin(i)[2:]])))