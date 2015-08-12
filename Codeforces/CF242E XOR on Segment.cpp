#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXB = 20;

int n, m;
int a[MAXN];

struct Bits {
    int b[MAXB];
    long long sum() const {
        long long ret = 0;
        for (int i = 0; i < MAXB; ++i) {
            ret += (1LL << i) * b[i];
        }
        return ret;
    }
};

Bits operator +(const Bits &a, const Bits &b) {
    Bits bits;
    for (int i = 0; i < MAXB; ++i) {
        bits.b[i] = a.b[i] + b.b[i];
    }
    return bits;
}

struct TreeNode {
    int l, r, lazy;
    Bits bits;
} tree[MAXN * 3];

inline int lc(int x) {
    return x * 2;
}

inline int rc(int x) {
    return lc(x) + 1;
}

inline void pushUp(int x) {
    tree[x].bits = tree[lc(x)].bits + tree[rc(x)].bits;
}

inline void applyLazy(int x, int lazy) {
    if (lazy) {
        int len = tree[x].r - tree[x].l + 1;
        for (int i = 0; i < MAXB; ++i) {
            if (lazy & (1 << i)) {
                tree[x].bits.b[i] = len - tree[x].bits.b[i];
            }
        }
    }
}

inline void pushDown(int x) {
    if (tree[x].lazy) {
        tree[lc(x)].lazy ^= tree[x].lazy;
        tree[rc(x)].lazy ^= tree[x].lazy;
        applyLazy(lc(x), tree[x].lazy);
        applyLazy(rc(x), tree[x].lazy);
        tree[x].lazy = 0;
    }
}

void build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lazy = 0;
    if (l == r) {
        for (int i = 0; i < MAXB; ++i) {
            tree[x].bits.b[i] = (a[l] & (1 << i)) > 0;
        }
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
    pushUp(x);
}

void update(int x, int l, int r, int val) {
    if (tree[x].l == l && tree[x].r == r) {
        tree[x].lazy ^= val;
        applyLazy(x, val);
        return;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (r <= mid) {
        update(lc(x), l, r, val);
    } else if (l > mid) {
        update(rc(x), l, r, val);
    } else {
        update(lc(x), l, mid, val);
        update(rc(x), mid + 1, r, val);
    }
    pushUp(x);
}

int bits[MAXB][MAXB];

Bits query(int x, int l, int r) {
    if (tree[x].l == l && tree[x].r == r) {
        return tree[x].bits;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (r <= mid) {
        return query(lc(x), l, r);
    }
    if (l > mid) {
        return query(rc(x), l, r);
    }
    return query(lc(x), l, mid) + query(rc(x), mid + 1, r);
}

int main() {
    int t, l, r, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    build(1, 1, n);
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d%d", &t, &l, &r);
        if (t == 1) {
            printf("%I64d\n", query(1, l, r).sum());
        } else {
            scanf("%d", &x);
            update(1, l, r, x);
        }
    }
    return 0;
}
