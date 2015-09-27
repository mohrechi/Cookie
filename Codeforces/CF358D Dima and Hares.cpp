#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 5;

int n, a[MAXN], b[MAXN], c[MAXN];
int dp[MAXN][2];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
    }
    dp[1][0] = a[1];
    dp[1][1] = b[1];
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0] + b[i], dp[i - 1][1] + a[i]);
        dp[i][1] = max(dp[i - 1][0] + c[i], dp[i - 1][1] + b[i]);
    }
    printf("%d\n", dp[n][0]);
    return 0;
}
