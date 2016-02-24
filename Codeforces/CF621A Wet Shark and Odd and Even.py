n = input()
a = map(int, raw_input().split(' '))
sum, first = 0, -1
for v in sorted(a):
    if (v & 1) == 1:
        if first == -1:
            first = v
        else:
            sum += v
    else:
        sum += v
if (sum & 1) == 1:
    sum += first
print sum
 