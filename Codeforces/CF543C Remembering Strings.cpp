#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20 + 1;

int n, m;
char s[MAXN][MAXN];
int a[MAXN][MAXN];
int cost[MAXN][MAXN], mask[MAXN][MAXN];
int dp[1 << MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int maxA = 0;
            for (int k = 0; k < n; ++k) {
                if (s[i][j] == s[k][j]) {
                    cost[i][j] += a[k][j];
                    mask[i][j] |= 1 << k;
                    maxA = max(maxA, a[k][j]);
                }
            }
            cost[i][j] -= maxA;
        }
    }
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 1; i < (1 << n); ++i) {
        int b = 0;
        for (int j = 0; j < n; ++j) {
            if ((1 << j) & i) {
                b = j;
                break;
            }
        }
        for (int j = 0; j < m; ++j) {
            dp[i] = min(dp[i], dp[i ^ (1 << b)] + a[b][j]);
            dp[i] = min(dp[i], dp[i & (i ^ mask[b][j])] + cost[b][j]);
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
