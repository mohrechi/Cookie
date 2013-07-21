import random
n, m = map(int, raw_input().split())
edge = {frozenset(map(int, raw_input().split())) for i in range(m)}
x = range(1, n + 1)
for t in range(1000):
    random.shuffle(x)
    if all(frozenset((x[i], x[i - 1])) not in edge for i in range(m)):
        for i in range(m):
            print x[i], x[i - 1]
        break;
else:
    print -1
