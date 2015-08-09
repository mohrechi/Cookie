#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int n, m;
int a[MAXN], pos[MAXN];
struct Query {
    int l, r, idx;
} q[MAXN];
long long ansL[MAXN], ansR[MAXN];
long long bit[MAXN];

bool sortByL(const Query &a, const Query &b) {
    return a.l < b.l;
}

bool sortByR(const Query &a, const Query &b) {
    return a.r < b.r;
}

inline int lowbit(int x) {
    return x & (-x);
}

void update(int x) {
    while (x <= n) {
        ++bit[x];
        x += lowbit(x);
    }
}

long long query(int x) {
    long long ret = 0;
    while (x > 0) {
        ret += bit[x];
        x -= lowbit(x);
    }
    return ret;
}

long long query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    for (int i = 0; i < m; ++i) {
        q[i].idx = i;
        scanf("%d%d", &q[i].l, &q[i].r);
    }
    sort(q, q + m, sortByL);
    int l = 0;
    for (int i = 0; i < m; ++i) {
        while (l < q[i].l - 1) {
            ++l;
            for (int j = a[l]; j <= n; j += a[l]) {
                update(pos[j]);
            }
        }
        ansL[q[i].idx] = query(q[i].l, q[i].r);
    }
    memset(bit, 0, sizeof(bit));
    sort(q, q + m, sortByR);
    int r = 0;
    for (int i = 0; i < m; ++i) {
        while (r < q[i].r) {
            ++r;
            for (int j = a[r]; j <= n; j += a[r]) {
                update(pos[j]);
            }
        }
        ansR[q[i].idx] = query(q[i].l, q[i].r);
    }
    for (int i = 0; i < m; ++i) {
        printf("%I64d\n", ansR[i] - ansL[i]);
    }
    return 0;
}
