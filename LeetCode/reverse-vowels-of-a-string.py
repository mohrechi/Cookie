def is_vowel(x):
    return x.lower() in ['a', 'e', 'i', 'o', 'u']

class Solution(object):
    def reverseVowels(self, s):
        s = list(s)
        v = list(reversed(filter(is_vowel, s)))
        idx = 0
        for i, c in enumerate(s):
            if is_vowel(c):
                s[i] = v[idx]
                idx += 1
        return ''.join(s)
