#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    map<char, int> num;
    for (int i = 0; i < t.length(); ++i) {
        ++num[t[i]];
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (num[s[i]] > 0) {
            --num[s[i]];
            ++ans1;
            s[i] = 0;
        } else {
            if ('a' <= s[i] && s[i] <= 'z') {
                s[i] = s[i] - 'a' + 'A';
            } else {
                s[i] = s[i] - 'A' + 'a';
            }
        }
    }
    for (int i = 0; i < s.length(); ++i) {
        if (num[s[i]] > 0) {
            --num[s[i]];
            ++ans2;
            s[i] = 0;
        }
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
