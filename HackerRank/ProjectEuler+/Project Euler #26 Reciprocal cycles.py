def get_cycle_len(num):
	rem = 1
	pos = {1: 0}
	index = 1
	while rem != 0:
		rem = rem * 10 % num
		if rem in pos.keys():
			return index - pos[rem]
		pos[rem] = index
		index += 1
	return 0
ans = []
last_pos = 0
last_cycle = 0
for i in range(1, 10001):
	cycle = get_cycle_len(i)
	if cycle > last_cycle:
		last_pos = i
		last_cycle = cycle
	ans.append(last_pos)
[print(ans[int(input()) - 2]) for _ in range(int(input()))]