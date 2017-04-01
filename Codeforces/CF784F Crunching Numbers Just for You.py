a = map(int, raw_input().split(' '))
b = 1.0
for i in xrange(5000000):
    b *= i
    b /= (i + 1)
print ' '.join(map(str, sorted(a[1:])))
