# Python 3
from math import sqrt

a, b = map(int, input().split(' '))
c, d = map(int, input().split(' '))
a = complex(a, b)
b = complex(c, d)
def tostr(c):
	s = ''
	r = '%.2f' % abs(c.real)
	if r != '0.00':
		s += '%.2f' % c.real
	t = '%.2f' % abs(c.imag)
	if t != '0.00':
		if r != '0.00':
			if c.imag < 0:
				s += ' - '
			else:
				s += ' + '
		s += t + 'i'
	return s
print(tostr(a + b))
print(tostr(a - b))
print(tostr(a * b))
print(tostr(a / b))
print(str(round(sqrt(a.real*a.real + a.imag*a.imag), 2)))
print(str(round(sqrt(b.real*b.real + b.imag*b.imag), 2)))