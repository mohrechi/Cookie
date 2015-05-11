# Python 2
a, b = map(float, raw_input().split(' '))
c, d = map(float, raw_input().split(' '))
a = complex(a, b)
b = complex(c, d)
def tostr(c):
    r = '%.2f' % abs(c.real)
    i = '%.2f' % abs(c.imag)
    if r == '0.00' and i == '0.00':
        return '0.00'
    if i == '0.00':
        return '%.2f' % c.real
    if r == '0.00':
        return '%.2fi' % c.imag
    if c.imag < 0:
        return '%.2f - %.2fi' % (c.real, abs(c.imag))
    return '%.2f + %.2fi' % (c.real, c.imag)
print(tostr(a + b))
print(tostr(a - b))
print(tostr(a * b))
print(tostr(a / b))
print('%.2f' % abs(a))
print('%.2f' % abs(b))