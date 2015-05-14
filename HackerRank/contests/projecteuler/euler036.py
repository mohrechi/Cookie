def is_palindrome(s):
	return s == s[::-1]
N, K = map(int, input().split(' '))
ans = 0
for i in range(1, N):
	if is_palindrome(str(i)):
		s = ''
		t = i
		while t > 0:
			s += chr(t % K + ord('0'))
			t //= K
		if is_palindrome(s):
			ans += i
print(ans)