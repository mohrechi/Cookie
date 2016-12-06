s = raw_input()


def check(s):
    cnt = [0] * 26
    for c in s:
        if c == '?':
            continue
        i = ord(c) - ord('A')
        cnt[i] += 1
        if cnt[i] > 1:
            return False
    cons, k = '', 0
    for i in xrange(26):
        if s[i] == '?':
            while cnt[k] != 0:
                k += 1
            cnt[k] = 1
            cons += chr(k + ord('A'))
        else:
            cons += s[i]
    return cons


def fill(s):
    cons = ''
    for c in s:
        if c == '?':
            cons += 'A'
        else:
            cons += c
    return cons

ans = -1
for i in xrange(0, len(s) - 25):
    cons = check(s[i:i + 26])
    if cons is not False:
        ans = fill(s[:i]) + cons + fill(s[i + 26:])
        break
print ans
