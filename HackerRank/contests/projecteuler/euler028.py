for _ in range(int(input())):
	N = (int(input()) + 1) // 2
	print((16*N*(N + 1)*(2*N + 1)//6 - 28*N*(N + 1)//2 +  16*N - 3) % 1000000007)