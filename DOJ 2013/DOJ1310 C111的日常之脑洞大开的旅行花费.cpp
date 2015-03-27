#include <bits/stdc++.h>
using namespace std;

int a[10];
int cost[600][20];

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        for (int i = 1; i <= 10; ++i) {
            scanf("%d", &a[i]);
        }
        scanf("%d", &n);
        memset(cost, 0x3f, sizeof(cost));
        memset(cost[0], 0, sizeof(cost[0]));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 10; ++j) {
                if (i - j >= 0) {
                    for (int k = 1; k <= 10; ++k) {
                        cost[i][j] = min(cost[i][j], cost[i - j][k] + a[j]);
                    }
                }
            }
        }
        int ans = 0x3f3f3f3f;
        for (int i = 1; i <= 10; ++i) {
            ans = min(ans, cost[n][i]);
        }
        cout << ans << endl;
    }
    return 0;
}
