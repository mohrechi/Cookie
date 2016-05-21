#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500 + 10;
const int MOD = 1e9 + 7;

int dp[MAXN][MAXN];

int main() {
    int T, N, M;
    for (int i = 0; i < MAXN; ++i) {
        dp[i][0] = dp[0][i] = 1;
    }
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < MAXN; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }
    cin >> T;
    while (T--) {
        cin >> N >> M;
        cout << dp[N][M] << endl;
    }
    return 0;
}
