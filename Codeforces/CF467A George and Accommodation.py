n = int(raw_input())
s = 0
for _ in range(n):
    a, b = map(int, raw_input().split(' '))
    if b - a >= 2:
        s += 1
print s