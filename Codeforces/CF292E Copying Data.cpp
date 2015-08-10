#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m;
int a[MAXN], b[MAXN];

struct TreeNode {
    int l, r, lazy, shift;
    inline int size() {
        return r - l + 1;
    }
} node[MAXN * 3];

inline int lc(int x) {
    return x * 2;
}

inline int rc(int x) {
    return lc(x) + 1;
}

inline void pushDown(int x) {
    if (node[x].lazy) {
        node[lc(x)].lazy = node[lc(x)].shift = node[x].shift;
        node[rc(x)].lazy = node[rc(x)].shift = node[x].shift + node[lc(x)].size();
        node[x].lazy = 0;
    }
}

void build(int x, int l, int r) {
    node[x].l = l;
    node[x].r = r;
    node[x].lazy = 0;
    node[x].shift = 0;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void update(int x, int l, int r, int val) {
    if (node[x].l == l && node[x].r == r) {
        node[x].lazy = node[x].shift = val;
        return;
    }
    pushDown(x);
    int mid = (node[x].l + node[x].r) / 2;
    if (r <= mid) {
        update(lc(x), l, r, val);
    } else if (l > mid) {
        update(rc(x), l, r, val);
    } else {
        update(lc(x), l, mid, val);
        update(rc(x), mid + 1, r, val + mid - l + 1);
    }
}

int query(int x, int pos) {
    if (node[x].l == node[x].r) {
        if (node[x].shift) {
            return a[node[x].shift];
        }
        return b[node[x].l];
    }
    pushDown(x);
    int mid = (node[x].l + node[x].r) / 2;
    if (pos <= mid) {
        return query(lc(x), pos);
    }
    return query(rc(x), pos);
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    build(1, 1, n);
    while (m--) {
        int t;
        int x, y, k;
        scanf("%d%d", &t, &x);
        if (t == 1) {
            scanf("%d%d", &y, &k);
            update(1, y, y + k - 1, x);
        } else {
            printf("%d\n", query(1, x));
        }
    }
    return 0;
}
