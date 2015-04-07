#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 10;

int n, a[MAXN], b[MAXN];
int dp[MAXN][MAXN];

int main() {
    while (cin >> n) {
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int j = 1; j <= n; ++j) {
            cin >> b[j];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i) {
            int maxDp = 0;
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (a[i] > b[j]) {
                    if (maxDp < dp[i - 1][j]) {
                        maxDp = dp[i - 1][j];
                    }
                }
                if (a[i] == b[j]) {
                    dp[i][j] = maxDp + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
