#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = 10000 + 10;

int n, m, a[MAXN];
int dpC[MAXN], dpT[MAXM];

int main() {
    int k;
    scanf("%d%d", &n, &m);
    while (n--) {
        scanf("%d", &k);
        for (int i = 1; i <= k; ++i) {
            scanf("%d", &a[i]);
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= k; ++i) {
            dpC[i] = 0;
            int len = k - i;
            for (int j = 1; j + len - 1 <= k; ++j) {
                dpC[i] = max(dpC[i], a[k] - (a[j + len - 1] - a[j - 1]));
            }
        }
        for (int i = m; i > 0; --i) {
            for (int j = 1; j <= i && j <= k; ++j) {
                dpT[i] = max(dpT[i], dpT[i - j] + dpC[j]);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) {
        ans = max(ans, dpT[i]);
    }
    printf("%d\n", ans);
    return 0;
}
