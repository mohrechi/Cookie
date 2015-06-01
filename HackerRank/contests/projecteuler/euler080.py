from decimal import *

n = int(input())
p = int(input())
getcontext().prec = p + 10
ans = 0
q = 1
for x in range(1, n+1):
    if q * q == x:
        q += 1
        continue
    for d in (Decimal(x).sqrt()).as_tuple()[1][:p]:
        ans += d
print(ans)