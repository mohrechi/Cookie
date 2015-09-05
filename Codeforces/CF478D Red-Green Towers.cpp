#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int dp[2][MAXN];

int main() {
    int r, g;
    cin >> r >> g;
    int ans = 0, sum = 0;
    int curr = 0, next = 1;
    memset(dp[curr], -1, sizeof(dp[curr]));
    dp[curr][0] = 1;
    bool hasNext = true;
    for (int h = 1; hasNext; ++h) {
        ans = 0;
        hasNext = false;
        memset(dp[next], -1, sizeof(dp[next]));
        for (int tr = 0; tr <= r; ++tr) {
            if (dp[curr][tr] != -1) {
                int tg = sum - tr;
                (ans += dp[curr][tr]) %= MOD;
                if (tr + h <= r) {
                    if (dp[next][tr + h] == -1) {
                        dp[next][tr + h] = 0;
                    }
                    (dp[next][tr + h] += dp[curr][tr]) %= MOD;
                    hasNext = true;
                }
                if (tg + h <= g) {
                    if (dp[next][tr] == -1) {
                        dp[next][tr] = 0;
                    }
                    (dp[next][tr] += dp[curr][tr]) %= MOD;
                    hasNext = true;
                }
            }
        }
        sum += h;
        swap(next, curr);
    }
    cout << ans << endl;
    return 0;
}
