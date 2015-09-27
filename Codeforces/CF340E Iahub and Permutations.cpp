#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 10;
const int MOD = 1e9 + 7;

int n, a[MAXN];
int dp[MAXN][MAXN];

int get(int x, int y) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    dp[x][y] = 0;
    if (x > 1) {
        dp[x][y] += (long long)get(x - 2, y + 1) * (x - 1) % MOD;
        dp[x][y] %= MOD;
    }
    if (y) {
        dp[x][y] += (long long)get(x - 1, y) * y % MOD;
        dp[x][y] %= MOD;
    }
    return dp[x][y];
}

int main() {
    int x = 0, y = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] == -1) {
            ++x;
        } else {
            if (a[a[i]] == -1) {
                ++y;
            }
        }
    }
    x -= y;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[0][i] = (long long)dp[0][i - 1] * i % MOD;
    }
    dp[1][0] = 0;
    printf("%d\n", get(x, y));
    return 0;
}
