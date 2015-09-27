#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int num = 0;
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        if (*it == '+') {
            if (--num < 0) {
                num = 0;
            }
        } else {
            ++num;
        }
    }
    int ans = num;
    for (auto c : s) {
        if (c == '+') {
            if (++num > ans) {
                ans = num;
            }
        } else {
            --num;
        }
    }
    cout << ans << endl;
    return 0;
}
