#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
const int MAXK = 10 + 2;
const int MOD = 1e8;

int n1, n2, k1, k2;
int dp[MAXN][MAXN][2];

int main() {
    cin >> n1 >> n2 >> k1 >> k2;
    for (int i = 1; i <= k1; ++i) {
        dp[i][0][0] = 1;
    }
    for (int j = 1; j <= k2; ++j) {
        dp[0][j][1] = 1;
    }
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            for (int k = 1; k <= min(i, k1); ++k) {
                dp[i][j][0] += dp[i - k][j][1];
                if (dp[i][j][0] >= MOD) {
                    dp[i][j][0] %= MOD;
                }
            }
            for (int k = 1; k <= min(j, k2); ++k) {
                dp[i][j][1] += dp[i][j - k][0];
                if (dp[i][j][1] >= MOD) {
                    dp[i][j][1] %= MOD;
                }
            }
        }
    }
    cout << (dp[n1][n2][0] + dp[n1][n2][1]) % MOD << endl;
    return 0;
}
