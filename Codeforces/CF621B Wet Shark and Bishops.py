n = int(raw_input())
ca, cb = [0] * 2000, [0] * 2000
for i in xrange(n):
    x, y = map(int, raw_input().split(' '))
    ca[x - y + 1000] += 1
    cb[(1001 - x) - y + 1000] += 1
ans = 0
for c in ca + cb:
    ans += c * (c - 1) / 2
print ans
