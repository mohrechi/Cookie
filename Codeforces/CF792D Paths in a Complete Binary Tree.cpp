#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, u;
    int h, q;
    string s;
    ios::sync_with_stdio(false);
    cin >> n >> q;
    for (h = 1; ; ++h) {
        if ((1LL << h) == (n + 1)) {
            break;
        }
    }
    while (q--) {
        cin >> u >> s;
        int ch = 1;
        long long ans = (n + 1) >> 1;
        vector<long long> path = {ans};
        while (ans != u) {
            if (u < ans) {
                ++ch;
                ans -= 1LL << (h - ch);
                path.push_back(ans);
            } else {
                ++ch;
                ans += 1LL << (h - ch);
                path.push_back(ans);
            }
        }
        for (auto c : s) {
            switch (c) {
            case 'L':
                if (ch == h) {
                    continue;
                }
                ++ch;
                ans -= 1LL << (h - ch);
                path.push_back(ans);
                break;
            case 'R':
                if (ch == h) {
                    continue;
                }
                ++ch;
                ans += 1LL << (h - ch);
                path.push_back(ans);
                break;
            case 'U':
                if (ch == 1) {
                    continue;
                }
                --ch;
                path.pop_back();
                ans = *path.rbegin();
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
