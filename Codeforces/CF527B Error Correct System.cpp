#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;
    while (cin >> n >> s >> t) {
        int ans = 0;
        int x = -1, y = -1;
        int dec = 0;
        map<char, map<char, int>> chars;
        for (int i = 0; i < n; ++i) {
            if (s[i] != t[i]) {
                ++ans;
                chars[s[i]][t[i]] = i + 1;
            }
        }
        for (int i = 0; i < n && dec < 2; ++i) {
            if (s[i] != t[i]) {
                for (int c = 'a'; c <= 'z'; ++c) {
                    if (chars[t[i]][c]) {
                        if (c != s[i]) {
                            if (dec == 0) {
                                x = i + 1;
                                y = chars[t[i]][c];
                                dec = 1;
                            }
                        } else {
                            x = i + 1;
                            y = chars[t[i]][c];
                            dec = 2;
                            break;
                        }
                    }
                }
            }
        }
        cout << ans - dec << endl;
        cout << x << " " << y << endl;
    }
    return 0;
}
