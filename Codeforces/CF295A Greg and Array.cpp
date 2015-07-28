#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int cnt[MAXN], l[MAXN], r[MAXN], d[MAXN];
long long a[MAXN], inc[MAXN];

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%I64d", &a[i]);
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &l[i], &r[i], &d[i]);
    }
    int x, y;
    while (k--) {
        scanf("%d%d", &x, &y);
        ++cnt[x];
        --cnt[y + 1];
    }
    int num = 0;
    for (int i = 1; i <= m; ++i) {
        num += cnt[i];
        auto val = (long long)d[i] * num;
        inc[l[i]] += val;
        inc[r[i] + 1] -= val;
    }
    long long carry = 0;
    for (int i = 1; i <= n; ++i) {
        carry += inc[i];
        printf("%I64d ", a[i] + carry);
    }
    return 0;
}
