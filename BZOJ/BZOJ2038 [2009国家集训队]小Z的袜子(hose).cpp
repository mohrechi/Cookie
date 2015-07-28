#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 50000 + 10;

int n, m;
int c[MAXN], cnt[MAXN];
int block[MAXN];
struct Query {
    int idx, l, r;
    inline int len() {
        return r - l + 1;
    }
    bool operator <(const Query &query) const {
        if (block[l] == block[query.l]) {
            return r < query.r;
        }
        return l < query.l;
    }
} query[MAXN];
long long num, a[MAXN], b[MAXN];

long long gcd(long long x, long long y) {
    return y == 0 ? x : gcd(y, x % y);
}

void update(int pos, int val) {
    num -= (long long)cnt[c[pos]] * (cnt[c[pos]] - 1);
    cnt[c[pos]] += val;
    num += (long long)cnt[c[pos]] * (cnt[c[pos]] - 1);
}

int main() {
    while (scanf("%d%d", &n, &m) != EOF) {
        int len = sqrt((double)n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &c[i]);
            block[i] = (i - 1) / len;
        }
        for (int i = 0; i < m; ++i) {
            query[i].idx = i;
            scanf("%d%d", &query[i].l, &query[i].r);
        }
        sort(query, query + m);
        int l = 1, r = 0;
        num = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < m; ++i) {
            while (r < query[i].r) {
                update(++r, 1);
            }
            while (r > query[i].r) {
                update(r--, -1);
            }
            while (l < query[i].l) {
                update(l++, -1);
            }
            while (l > query[i].l) {
                update(--l, 1);
            }
            a[query[i].idx] = num;
            b[query[i].idx] = (long long)query[i].len() * (query[i].len() - 1);
        }
        for (int i = 0; i < m; ++i) {
            if (a[i] == 0) {
                b[i] = 1;
            } else {
                long long g = gcd(a[i], b[i]);
                a[i] /= g;
                b[i] /= g;
            }
            printf("%lld/%lld\n", a[i], b[i]);
        }
    }
    return 0;
}
