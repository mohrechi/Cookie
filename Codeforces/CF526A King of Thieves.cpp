#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        bool valid = false;
        for (int i = 0; i < s.length() && !valid; ++i) {
            if (s[i] != '*') {
                continue;
            }
            for (int j = 1; j < s.length() && !valid; ++j) {
                for (int k = 0, t = i + j; k <= 4; ++k, t += j) {
                    if (k == 4) {
                        valid = true;
                    } else {
                        if (s[t] != '*') {
                            break;
                        }
                    }
                }
            }
        }
        cout << (valid ? "yes" : "no") << endl;
    }
    return 0;
}
