# Python 3
import re

n = int(input())
for _ in range(n):
	if re.match(r'^[7-9]\d{9}$', input()):
		print('YES')
	else:
		print('NO')