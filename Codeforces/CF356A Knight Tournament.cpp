#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 15;

int n, m;
struct TreeNode {
    int l, r, val;
} tree[MAXN * 4];

inline int lc(int x) {
    return x <<= 1;
}

inline int rc(int x) {
    return lc(x) + 1;
}

inline void pushDown(int x) {
    if (tree[x].val) {
        if (tree[lc(x)].val == 0) {
            tree[lc(x)].val = tree[x].val;
        }
        if (tree[rc(x)].val == 0) {
            tree[rc(x)].val = tree[x].val;
        }
    }
}

void build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].val = 0;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void update(int x, int l, int r, int val) {
    if (l > r || tree[x].val) {
        return;
    }
    if (tree[x].l == l && tree[x].r == r) {
        tree[x].val = val;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid) {
        update(lc(x), l, r, val);
    } else if (l > mid) {
        update(rc(x), l, r, val);
    } else {
        update(lc(x), l, mid, val);
        update(rc(x), mid + 1, r, val);
    }
}

int query(int x, int pos) {
    if (tree[x].l == tree[x].r) {
        return tree[x].val;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid) {
        return query(lc(x), pos);
    }
    return query(rc(x), pos);
}

int main() {
    int l, r, x;
    scanf("%d%d", &n, &m);
    build(1, 1, n);
    while (m--) {
        scanf("%d%d%d", &l, &r, &x);
        update(1, l, x - 1, x);
        update(1, x + 1, r, x);
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", query(1, i));
    }
    putchar('\n');
    return 0;
}
