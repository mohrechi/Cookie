# Python 3
from datetime import datetime

fmt = '%a %d %b %Y %H:%M:%S %z'
T = int(input())
for _ in range(T):
	t1 = datetime.strptime(input(), fmt)
	t2 = datetime.strptime(input(), fmt)
	print(abs(int((t1 - t2).total_seconds())))
