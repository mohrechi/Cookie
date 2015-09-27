#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXD = 300 + 10;

int n, m, s, e;
int a[MAXN];
int b[MAXN];
int dp[MAXD][MAXN];
vector<int> pos[MAXN];

int main() {
    scanf("%d%d%d%d", &n, &m, &s, &e);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int j = 1; j <= m; ++j) {
        scanf("%d", &b[j]);
        pos[b[j]].push_back(j);
    }
    for (int i = 0; i < MAXN; ++i) {
        pos[i].push_back(MAXN);
    }
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    memset(dp[0], 0, sizeof(dp[0]));
    for (int i = 1; i <= s / e; ++i) {
        for (int j = i; j <= n; ++j) {
            if (dp[i - 1][j - 1] != -1) {
                dp[i][j] = dp[i][j - 1];
                int k = pos[a[j]][lower_bound(pos[a[j]].begin(), pos[a[j]].end(), dp[i - 1][j - 1] + 1) - pos[a[j]].begin()];
                if (k == MAXN) {
                    continue;
                }
                if (dp[i][j] == -1 || dp[i][j] > k) {
                    dp[i][j] = k;
                }
                if (dp[i][j] + j <= s - i * e) {
                    ans = max(ans, i);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
