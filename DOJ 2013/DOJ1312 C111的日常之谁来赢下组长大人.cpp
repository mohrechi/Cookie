#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

int n, a[MAXN];
long long dp[MAXN][MAXN];

long long get(int i, int j) {
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    if (i + 1 >= j) {
        return dp[i][j] = 0;
    }
    dp[i][j] = 0x7fffffffffffffffLL;
    for (int k = i + 1; k < j; ++k) {
        dp[i][j] = min(dp[i][j], get(i, k) + get(k, j) + a[i] * a[k] * a[j]);
    }
    return dp[i][j];
}

int main() {
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << get(0, n - 1) << endl;
    }
    return 0;
}
