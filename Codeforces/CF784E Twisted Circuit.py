a = input()
b = input()
c = input()
d = input()
aa = a ^ b
bb = c | d
cc = b & c
dd = a ^ d
ab = aa & bb
cd = cc | dd
print ab ^ cd
