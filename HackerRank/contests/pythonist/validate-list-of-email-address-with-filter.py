# Python 3
import re
	
n = int(input())
d = [input() for _ in range(n)]
print(sorted(list(filter(lambda x: re.match(r'^[a-zA-Z0-9_-]+@[a-zA-Z0-9]+\.[a-zA-Z0-9]{1,3}$', x), d))))
