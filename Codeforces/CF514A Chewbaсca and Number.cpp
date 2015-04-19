#include <bits/stdc++.h>
using namespace std;

inline char invert(const char &c) {
    return 9 - (c - '0') + '0';
}

int main() {
    string s;
    while (cin >> s) {
        if ('5' <= s[0] && s[0] < '9') {
            s[0] = invert(s[0]);
        }
        for (int i = 1; i < s.length(); ++i) {
            if ('5' <= s[i] && s[i] <= '9') {
                s[i] = invert(s[i]);
            }
        }
        cout << s << endl;
    }
    return 0;
}
