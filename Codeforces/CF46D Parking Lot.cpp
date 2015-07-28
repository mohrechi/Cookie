#include <bits/stdc++.h>
using namespace std;
const int MAXB = 100 + 10;
const int MAXF = 100 + 10;
const int MAXL = 100000 + MAXB + MAXF + 10;
const int MAXN = 100 + 10;

int L, b, f;

struct Tree {
    int l, r, lazy;
    int freeL, freeR, freeMid, maxFree;
    inline int len() {
        return r - l + 1;
    }
} tree[MAXL * 3];

inline int lc(int x) {
    return x * 2;
}

inline int rc(int x) {
    return lc(x) + 1;
}

void pushUp(int x) {
    tree[x].freeL = tree[lc(x)].freeL;
    if (tree[lc(x)].freeL == tree[lc(x)].len()) {
         tree[x].freeL += tree[rc(x)].freeL;
    }
    tree[x].freeR = tree[rc(x)].freeR;
    if (tree[rc(x)].freeR == tree[rc(x)].len()) {
        tree[x].freeR += tree[lc(x)].freeR;
    }
    tree[x].freeMid = tree[lc(x)].freeR + tree[rc(x)].freeL;
    tree[x].maxFree = max(max(tree[lc(x)].maxFree, tree[rc(x)].maxFree), tree[x].freeMid);
}

inline void fill(int x) {
    tree[x].freeL = tree[x].freeR = tree[x].freeMid = tree[x].maxFree = tree[x].r - tree[x].l + 1;
}

inline void remove(int x) {
    tree[x].freeL = tree[x].freeR = tree[x].freeMid = tree[x].maxFree = 0;
}

void pushDown(int x) {
    if (tree[x].lazy) {
        if (tree[x].lazy == 1) {
            fill(lc(x));
            fill(rc(x));
        } else {
            remove(lc(x));
            remove(rc(x));
        }
        tree[lc(x)].lazy = tree[x].lazy;
        tree[rc(x)].lazy = tree[x].lazy;
        tree[x].lazy = 0;
    }
}

void build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lazy = 0;
    fill(x);
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void update(int x, int l, int r, int dir) {
    if (tree[x].l == l && tree[x].r == r) {
        if (dir == 1) {
            fill(x);
        } else {
            remove(x);
        }
        tree[x].lazy = dir;
        return;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (r <= mid) {
        update(lc(x), l, r, dir);
    } else if (l > mid) {
        update(rc(x), l, r, dir);
    } else {
        update(lc(x), l, mid, dir);
        update(rc(x), mid + 1, r, dir);
    }
    pushUp(x);
}

int query(int x, int len) {
    if (tree[x].maxFree < len) {
        return -1;
    }
    if (tree[lc(x)].maxFree >= len) {
        return query(lc(x), len);
    }
    if (tree[x].freeMid >= len) {
        return tree[lc(x)].r - tree[lc(x)].freeR + 1;
    }
    return query(rc(x), len);
}

int pos[MAXN], len[MAXN];

int main() {
    int n, op;
    scanf("%d%d%d", &L, &b, &f);
    build(1, 0, L + b + f - 1);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", &op, &len[i]);
        if (op == 1) {
            pos[i] = query(1, b + len[i] + f);
            if (pos[i] != -1) {
                update(1, pos[i] + b, pos[i] + b + len[i] - 1, -1);
            }
            printf("%d\n", pos[i]);
        } else {
            update(1, pos[len[i]] + b, pos[len[i]] + b + len[len[i]] - 1, 1);
        }
    }
    return 0;
}
