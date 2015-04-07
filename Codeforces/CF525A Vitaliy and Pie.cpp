#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    while (cin >> n >> s) {
        int ans = 0;
        map<int, int> keys;
        for (char c : s) {
            if ('a' <= c && c <= 'z') {
                ++keys[c - 'a' + 'A'];
            } else {
                if (keys[c] > 0) {
                    --keys[c];
                } else {
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
