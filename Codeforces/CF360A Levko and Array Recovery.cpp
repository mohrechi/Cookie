#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
const int INF = 1e9;

int n, m;
int t[MAXN], l[MAXN], r[MAXN], d[MAXN];

int sum[MAXN], ans[MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        ans[i] = 1e9;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d%d", &t[i], &l[i], &r[i], &d[i]);
        if (t[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++j) {
                sum[j] += d[i];
            }
        } else {
            for (int j = l[i]; j <= r[i]; ++j) {
                ans[j] = min(ans[j], d[i] - sum[j]);
            }
        }
    }
    bool valid = true;
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < m and valid; ++i) {
        if (t[i] == 1) {
            for (int j = l[i]; j <= r[i]; ++j) {
                sum[j] += d[i];
            }
        } else {
            valid = false;
            for (int j = l[i]; j <= r[i]; ++j) {
                if (ans[j] + sum[j] == d[i]) {
                    valid = true;
                    break;
                }
            }
        }
    }
    if (valid) {
        puts("YES");
        for (int i = 1; i <= n; ++i) {
            printf("%d ", ans[i]);
        }
        putchar('\n');
    } else {
        puts("NO");
    }
    return 0;
}
