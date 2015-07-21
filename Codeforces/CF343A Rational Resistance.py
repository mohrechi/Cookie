a, b = map(int, raw_input().split())
c = 0
while a and b:
    c += a / b
    a, b = b, a % b
print c
