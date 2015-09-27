#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int t, k;
int dp[MAXN];

int main() {
    int a, b;
    cin >> t >> k;
    dp[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        dp[i] = dp[i - 1];
        if (i - k >= 0) {
            dp[i] += dp[i - k];
            if (dp[i] >= MOD) {
                dp[i] -= MOD;
            }
        }
    }
    for (int i = 1; i < MAXN; ++i) {
        dp[i] += dp[i - 1];
        if (dp[i] >= MOD) {
            dp[i] -= MOD;
        }
    }
    while (t--) {
        cin >> a >> b;
        cout << (dp[b] + MOD - dp[a - 1])  % MOD << endl;
    }
    return 0;
}
