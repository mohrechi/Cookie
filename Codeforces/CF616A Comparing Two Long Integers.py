a, b = raw_input(), raw_input()
n = max(len(a), len(b))
a, b = a.zfill(n), b.zfill(n)
print ['<', '=', '>'][cmp(a, b) + 1]
