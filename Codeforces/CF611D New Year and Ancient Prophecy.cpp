#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 5;
const int MOD = 1e9 + 7;

int n;
char digits[MAXN];
int diff[MAXN][MAXN];
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];

int main() {
    cin >> n >> (digits + 1);
    for (int i = n; i >= 1; --i) {
        for (int j = n; j > i; --j) {
            if (digits[i] != digits[j]) {
                diff[i][j] = 0;
            } else {
                diff[i][j] = diff[i + 1][j + 1] + 1;
            }
        }
    }
    for (int j = 1; j <= n; ++j) {
        dp[1][j] = 1;
        pre[1][j] = dp[1][j];
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if (digits[i] == '0') {
                dp[i][j] = 0;
            } else {
                int len = j - i + 1;
                if (i - len >= 1) {
                    int pos = diff[i - len][i];
                    if (pos < len && digits[i + pos] > digits[i - len + pos]) {
                        dp[i][j] = dp[i - len][i - 1];
                    }
                }
                (dp[i][j] += (pre[i - 1][i - 1] - pre[max(0, i - len)][i - 1] + MOD) % MOD) %= MOD;
            }
            pre[i][j] = (pre[i - 1][j] + dp[i][j]) % MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        (ans += dp[i][n]) %= MOD;
    }
    cout << ans << endl;
    return 0;
}
