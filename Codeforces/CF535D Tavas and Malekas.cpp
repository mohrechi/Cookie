#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int n, m;
string p;
vector<int> x;

long long powMod(long long y) {
    long long res = 1;
    while (y--) {
        res = res * 26 % MOD;
    }
    return res;
}

int main() {
    while (cin >> n >> m) {
        cin >> p;
        x = vector<int>(m);
        for (int i = 0; i < m; ++i) {
            cin >> x[i];
        }
        if (m == 0) {
            cout << powMod(n) << endl;
        } else {
            vector<int> next(p.length() + 1);
            next[0] = -1;
            for (int i = 0, j = -1; i < (int)p.length(); ++i) {
                while (j != -1 && p[i] != p[j]) {
                    j = next[j];
                }
                next[i + 1] = ++j;
            }
            vector<bool> valid(p.length() + 1, false);
            int index = next[p.length()];
            while (index >= 0) {
                valid[index] = true;
                index = next[index];
            }
            long long ans = powMod(x[0] - 1);
            for (int i = 1; i < m; ++i) {
                if (x[i] - x[i - 1] >= (int)p.length()) {
                    ans = ans * powMod(x[i] - x[i - 1] - (int)p.length()) % MOD;
                } else {
                    if (!valid[x[i - 1] + (int)p.length() - x[i]]) {
                        ans = 0;
                        break;
                    }
                }
            }
            ans = ans * powMod(n - x[m - 1] - p.length() + 1) % MOD;
            cout << ans << endl;
        }
    }
    return 0;
}
