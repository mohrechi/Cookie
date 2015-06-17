#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;

int a[MAXN], dp[MAXN][MAXN];

int main() {
    int n, m, b, mod;
    ios::sync_with_stdio(false);
    cin >> n >> m >> b >> mod;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k <= b; ++k) {
                if (dp[j][k] and j + 1 <= m and k + a[i] <= b) {
                    dp[j + 1][k + a[i]] += dp[j][k];
                    dp[j + 1][k + a[i]] %= mod;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= b; ++i) {
        ans += dp[m][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
