n, m = map(int, raw_input().split())
s = [raw_input() for i in range(n)]
sumH = [sum([1 for j in range(m) if s[i][j] == 'S']) for i in range(n)]
sumV = [sum([1 for i in range(n) if s[i][j] == 'S']) for j in range(m)]
print n * m - sum([1 for i in range(n) for j in range(m) if sumH[i] > 0 and sumV[j] > 0])
