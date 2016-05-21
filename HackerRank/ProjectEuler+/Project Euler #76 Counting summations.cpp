#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
const int MOD = 1e9 + 7;

int dp[MAXN][MAXN];

int get(int x, int m) {
    if (dp[x][m] != -1) {
        return dp[x][m];
    }
    if (x < m) {
        return dp[x][m] = get(x, x);
    }
    dp[x][m] = 0;
    for (int i = 1; i <= m; ++i) {
        dp[x][m] += get(x - i, i);
        if (dp[x][m] >= MOD) {
            dp[x][m] -= MOD;
        }
    }
    return dp[x][m];
}

int main() {
    int T, N;
    cin >> T;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;
    while (T--) {
        cin >> N;
        cout << get(N, N) - 1 << endl;
    }
    return 0;
}
