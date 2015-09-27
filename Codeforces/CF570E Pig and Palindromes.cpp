#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;
const int MOD = 1e9 + 7;

int n, m;
char s[MAXN][MAXN];
long long dp[2][MAXN][MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
    }
    int len = n + m - 1;
    int half = (len + 1) / 2;
    long long ans = 0;
    if (s[1][1] == s[n][m]) {
        int curr = 1, prev = 0;
        dp[curr][1][n] = 1;
        for (int k = 2; k <= half; ++k) {
            swap(curr, prev);
            memset(dp[curr], 0, sizeof(dp[curr]));
            for (int r1 = 1; r1 <= n; ++r1) {
                int c1 = k - r1 + 1;
                if (1 <= c1 && c1 <= m) {
                    for (int r2 = 1; r2 <= n; ++r2) {
                        int c2 = m - (k - (n - r2)) + 1;
                        if (1 <= c2 && c2 <= m) {
                            if (s[r1][c1] == s[r2][c2]) {
                                dp[curr][r1][r2] = (dp[prev][r1][r2] +
                                                    dp[prev][r1 - 1][r2] +
                                                    dp[prev][r1][r2 + 1] +
                                                    dp[prev][r1 - 1][r2 + 1]) % MOD;
                                if (k == half) {
                                    if ((r1 == r2 && c1 == c2) ||
                                        (r1 == r2 && c1 + 1 == c2) ||
                                        (c1 == c2 && r1 + 1 == r2)) {
                                        ans = (ans + dp[curr][r1][r2]) % MOD;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
