b, d, s = map(int, raw_input().split(' '))
cases = [
    (0, 1, 0), (0, 0, 0), (0, 1, 1),
    (1, 0, 1), (1, 1, 0), (1, 0, 0), (0, 0, 1)
]
ans = -1
for case in cases:
    tb = b - case[0]
    td = d - case[1]
    ts = s - case[2]
    if tb >= 0 and td >= 0 and ts >= 0:
        m = max(tb, td, ts)
        miss = m - tb + m - td + m - ts
        if ans == -1 or ans > miss:
            ans = miss
print ans
