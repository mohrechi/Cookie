s = map(int, raw_input())
ans = 'Yes'
rev = [8, -1, -1, 3, 6, 9, 4, 7, 0, 5]
for i in xrange((len(s) + 1) // 2):
    if s[len(s) - i - 1] != rev[s[i]]:
        ans = 'No'
        break
print ans
