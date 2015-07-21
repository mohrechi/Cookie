#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 10;
const int MOD = 1e9 + 7;

int n, m;
char s[MAXN][MAXN];
int up[MAXN][MAXN], down[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> (s[i] + 1);
    }
    up[1][1] = down[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            if (s[i][j] == '.') {
                up[i][j] = (up[i - 1][j] + up[i][j - 1]) % MOD;
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s[i][j] == '.') {
                down[i][j] = (down[i - 1][j] + down[i][j - 1]) % MOD;
            }
        }
    }
    long long a = 1LL * up[n - 1][m] * down[n][m - 1] % MOD;
    long long b = 1LL * up[n][m - 1] * down[n - 1][m] % MOD;
    cout << (a - b + MOD) % MOD << endl;
    return 0;
}
