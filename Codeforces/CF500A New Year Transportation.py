n, t = map(int, input().split(' '))
a = list(map(int, input().split(' ')))
a.append(1)
i = 0
while i < n:
    if i == t - 1:
        print("YES")
        break
    else:
        i += a[i]
if i >= n:
    print("NO")