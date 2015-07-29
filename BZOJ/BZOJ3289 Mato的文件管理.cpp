#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50000 + 10;

int n, m, q, a[MAXN];
int blockLen;
struct Query {
    int idx, l, r;
    bool operator <(const Query &query) const {
        if ((l - 1) / blockLen == (query.l - 1) / blockLen) {
            return r < query.r;
        }
        return l < query.l;
    }
} query[MAXN];

int ans[MAXN];
long long num;
set<int> vals;
map<int, int> idx;

int c[MAXN];

void update(int x, int val) {
    while (x <= m) {
        c[x] += val;
        x += x & -x;
    }
}

int queryNum(int x) {
    int ret = 0;
    while (x > 0) {
        ret += c[x];
        x -= x & -x;
    }
    return ret;
}

int queryNum(int l, int r) {
    if (l > r) {
        return 0;
    }
    return queryNum(r) - queryNum(l - 1);
}

void insertLeft(int x) {
    num += queryNum(1, x - 1);
    update(x, 1);
}

void insertRight(int x) {
    num += queryNum(x + 1, m);
    update(x, 1);
}

void removeLeft(int x) {
    num -= queryNum(1, x - 1);
    update(x, -1);
}

void removeRight(int x) {
    num -= queryNum(x + 1, m);
    update(x, -1);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        vals.insert(a[i]);
    }
    m = 0;
    for (set<int>::iterator it = vals.begin(); it != vals.end(); ++it) {
        idx[*it] = ++m;
    }
    for (int i = 1; i <= n; ++i) {
        a[i] = idx[a[i]];
    }
    blockLen = sqrt(n);
    scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        query[i].idx = i;
        scanf("%d%d", &query[i].l, &query[i].r);
    }
    sort(query, query + q);
    int l = 1, r = 0;
    for (int i = 0; i < q; ++i) {
        while (r < query[i].r) {
            insertRight(a[++r]);
        }
        while (r > query[i].r) {
            removeRight(a[r--]);
        }
        while (l < query[i].l) {
            removeLeft(a[l++]);
        }
        while (l > query[i].l) {
            insertLeft(a[--l]);
        }
        ans[query[i].idx] = num;
    }
    for (int i = 0; i < q; ++i) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
