#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 200000 + 10;

struct Tree {
    int l, r, sum, val;
} tree[MAXN * 3];

inline int lc(int x) {
    return x * 2;
}

inline int rc(int x) {
    return lc(x) + 1;
}

void build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].sum = r - l + 1;
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void update(int x, int num, int val) {
    --tree[x].sum;
    if (tree[x].l == tree[x].r) {
        tree[x].sum = 0;
        tree[x].val = val;
        return;
    }
    int leftSum = tree[lc(x)].sum;
    if (num <= leftSum) {
        update(lc(x), num, val);
    } else {
        update(rc(x), num - leftSum, val);
    }
}

int query(int x, int pos) {
    if (tree[x].l == tree[x].r) {
        return tree[x].val;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (pos <= mid) {
        return query(lc(x), pos);
    }
    return query(rc(x), pos);
}

int n;
int pos[MAXN], val[MAXN];

int main() {
    while (scanf("%d", &n) != EOF) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &pos[i], &val[i]);
        }
        build(1, 0, n - 1);
        for (int i = n; i > 0; --i) {
            update(1, pos[i] + 1, val[i]);
        }
        for (int i = 0; i < n; ++i) {
            if (i) {
                putchar(' ');
            }
            printf("%d", query(1, i));
        }
        putchar('\n');
    }
    return 0;
}
