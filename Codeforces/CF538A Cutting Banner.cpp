#include <bits/stdc++.h>
using namespace std;

const char *BANNER = "CODEFORCES";

int main() {
    int len = strlen(BANNER);
    string s;
    while (cin >> s) {
        int left = 0, right = len - 1;
        for (int i = 0; i < s.length() && left < len; ++i, ++left) {
            if (s[i] != BANNER[left]) {
                break;
            }
        }
        for (int i = s.length() - 1; i >= 0 && right >= 0; --i, --right) {
            if (s[i] != BANNER[right]) {
                break;
            }
        }
        --left, ++right;
        cout << (left + 1 >= right ? "YES" : "NO") << endl;
    }
    return 0;
}
