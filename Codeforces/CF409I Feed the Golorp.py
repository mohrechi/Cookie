sa, sb = raw_input().split('):-')
sa = list(sa[2:])
sb = sb[:-1]
for i in xrange(len(sa)):
    if sa[i] != '_':
        sa[i] = ','
a = ''.join(sa).split(',')
b = sb.split(',')
for i in xrange(len(b)):
    if '<' in b[i]:
        b[i] = b[i].split('<')
    else:
        b[i] = list(reversed(b[i].split('>')))
nums = {i: 0 for i in a}
while True:
    flag = True
    false = False
    for (na, nb) in b:
        if nums[na] >= nums[nb]:
            flag = False
            nums[nb] += 1
            if nums[nb] >= 10:
                false = True
                break
    if flag or false:
        break
if false:
    print 'false'
else:
    print ''.join(map(str, map(lambda x: nums[x], a)))
