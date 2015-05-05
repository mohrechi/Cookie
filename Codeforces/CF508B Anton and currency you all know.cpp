#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string s;
    while (cin >> s) {
        bool valid = false;
        for (auto c : s) {
            if (c % 2 == 0) {
                valid = true;
                break;
            }
        }
        if (!valid) {
            cout << -1 << endl;
            continue;
        }
        bool changed = false;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] % 2 == 0) {
                if (s[i] < s[n - 1]) {
                    swap(s[i], s[n - 1]);
                    changed = true;
                    break;
                }
            }
        }
        if (!changed) {
            for (int i = n - 1; i >= 0; --i) {
                if (s[i] % 2 == 0) {
                    swap(s[i], s[n - 1]);
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
