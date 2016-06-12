from sys import stdout


def is_factor(x):
    print x
    stdout.flush()
    return raw_input() == 'yes'

a = [2, 3, 4, 5, 7, 9, 11, 13, 16, 17, 19, 23, 25, 29, 31, 37, 41, 43, 47, 49]
l = len(filter(is_factor, a))
if l < 2:
    print 'prime'
else:
    print 'composite'
