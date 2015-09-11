#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 5;
const int MAXM = 4e4 + 5;

int n, x, y;
int h[MAXN];
int dp[2][MAXM][2];

inline void setVal(int &x, int val) {
    if (val != -1 && (x == -1 || x > val)) {
        x = val;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &h[i]);
    }
    int curr = 0, prev = 1, total = 0;
    memset(dp[curr], -1, sizeof(dp[curr]));
    dp[curr][0][0] = dp[curr][1][1] = 0;
    for (int i = 1; i <= n; ++i) {
        swap(curr, prev);
        memset(dp[curr], -1, sizeof(dp[curr]));
        for (int r = 0; r <= total; ++r) {
            int b = total - r;
            if (dp[prev][r][0] != -1) {
                if (r + h[i] <= x) {
                    setVal(dp[curr][r + h[i]][0], dp[prev][r][0]);
                }
                if (b + h[i] <= y) {
                    setVal(dp[curr][r][1], dp[prev][r][0] + min(h[i - 1], h[i]));
                }
            }
            if (dp[prev][r][1] != -1) {
                if (r + h[i] <= x) {
                    setVal(dp[curr][r + h[i]][0], dp[prev][r][1] + min(h[i - 1], h[i]));
                }
                if (b + h[i] <= y) {
                    setVal(dp[curr][r][1], dp[prev][r][1]);
                }
            }
        }
        total += h[i];
    }
    int ans = -1;
    for (int i = 0; i <= total; ++i) {
        setVal(ans, dp[curr][i][0]);
        setVal(ans, dp[curr][i][1]);
    }
    printf("%d\n", ans);
    return 0;
}
