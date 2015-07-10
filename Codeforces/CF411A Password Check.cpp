#include <bits/stdc++.h>
using namespace std;

bool hasInterval(char *s, const char &l, const char &r) {
    if (l <= *s and *s <= r) {
        return true;
    }
    if (*s == 0) {
        return false;
    }
    return hasInterval(s + 1, l, r);
}

inline bool hasLarge(char *s) {
    return hasInterval(s, 'A', 'Z');
}

inline bool hasSmall(char *s) {
    return hasInterval(s, 'a', 'z');
}

inline bool hasDigit(char *s) {
    return hasInterval(s, '0', '9');
}

int main() {
    char s[128];
    gets(s);
    if (strlen(s) >= 5 and hasLarge(s) and hasSmall(s) and hasDigit(s)) {
        puts("Correct");
    } else {
        puts("Too weak");
    }
    return 0;
}
