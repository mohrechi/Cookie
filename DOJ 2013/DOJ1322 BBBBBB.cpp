#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, a[MAXN], sum[MAXN];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i - 1] + a[i];
        }
        double ans = 0.0;
        for (int i = 0; i <= n / 2; ++i) {
            int cnt = n - i - i;
            if (cnt > 0) {
                double score = (double)(sum[n - i] - sum[i]) / cnt;
                if (score > ans) {
                    ans = score;
                }
            }
        }
        printf("%.2f\n", ans);
    }
    return 0;
}
