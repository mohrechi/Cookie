N, K = map(int, input().split(' '))
pent_set = set()
pent_list = [0]
def get_pent(x):
	return x * (3 * x - 1) // 2
for i in range(1, N * 2):
	pent_list.append(get_pent(i))
	pent_set.add(pent_list[-1])
for i in range(K + 1, N + 1):
	if (pent_list[i] - pent_list[i - K]) in pent_set or (pent_list[i] + pent_list[i - K]) in pent_set:
		print(pent_list[i])