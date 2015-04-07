a, b = map(int, raw_input().split(' '))
sum = 0
while a > 0 and b > 0:
    if a < b:
        a, b = b, a
    else:
        sum += a / b
        a %= b
print sum