#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;

int n, m, k;
long long p[MAXN];

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &p[i]);
        p[i] += p[i - 1];
    }
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));
    long long ans = 0;
    for (int i = m; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + p[i] - p[i - m]);
        }
        ans = max(ans, dp[i][k]);
    }
    cout << ans << endl;
    return 0;
}
