#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

int n, a[MAXN];
int pos[MAXN];
int dp[MAXN];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
        dp[i] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i] * 2; j <= a[n]; j += a[i]) {
            dp[pos[j]] = max(dp[pos[j]], dp[i] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
