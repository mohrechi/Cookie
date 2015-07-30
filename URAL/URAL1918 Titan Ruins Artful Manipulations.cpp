#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
const int MOD = 1e9 + 7;

int n;
long long dp[2][MAXN];
long long sum[2][MAXN];

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            dp[1][i] = 1;
            sum[1][i] = i;
        }
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i > j) {
                    dp[i & 1][j] = 0;
                } else {
                    (dp[i & 1][j] = dp[(i & 1) ^ 1][j] * j + sum[(i & 1) ^ 1][j - 1] - sum[(i & 1) ^ 1][i - 1] + MOD) %= MOD;
                    (sum[i & 1][j] = sum[i & 1][j - 1] + dp[i & 1][j]) %= MOD;
                }
            }
        }
        printf("%lld\n", dp[n & 1][n]);
    }
    return 0;
}
