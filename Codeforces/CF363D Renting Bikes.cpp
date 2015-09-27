#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n, m, a;
int b[MAXN], p[MAXN];

int main() {
    scanf("%d%d%d", &n, &m, &a);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &p[i]);
    }
    sort(b, b + n, greater<int>());
    sort(p, p + m);
    m = min(n, m);
    int l = 0, r = m, ans = 0;
    long long cost = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        long long person = 0, bike = 0;
        for (int i = 0, j = mid - 1; j >= 0; ++i, --j) {
            person += min(b[i], p[j]);
            bike += p[j];
        }
        if (a >= bike - person) {
            l = mid + 1;
            if (l > ans) {
                ans = mid;
                cost = max(0LL, person - (a - (bike - person)));
            }
        } else {
            r = mid - 1;
        }
    }
    printf("%d %I64d\n", ans, cost);
    return 0;
}
