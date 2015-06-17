MAXN = int(1e5) + 10
MOD = int(1e9) + 7
nums = [0 for _ in range(MAXN)]
nums[0] = 1
coins = [1, 2, 5, 10, 20, 50, 100, 200]
for coin in coins:
	for i in range(coin, MAXN):
		nums[i] += nums[i - coin]
		nums[i] %= MOD
[print(nums[int(input())]) for _ in range(int(input()))]