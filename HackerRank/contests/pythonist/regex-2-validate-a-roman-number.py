# Python 3
import re

s = input()
if re.match(r'^M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$', s):
	print('True')
else:
	print('False')