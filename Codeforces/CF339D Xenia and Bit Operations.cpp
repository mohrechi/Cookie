#include <bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 17) + 10;

int n, m;
int a[MAXN];

struct TreeNode {
    int l, r, d, v;
} node[MAXN * 3];

inline int lc(int x) {
    return x * 2;
}

inline int rc(int x) {
    return lc(x) + 1;
}

inline int pushUp(int d, int v1, int v2) {
    return d ? (v1 | v2) : (v1 ^ v2);
}

inline void pushUp(int x) {
    node[x].v = pushUp(node[x].d, node[lc(x)].v, node[rc(x)].v);
}

void build(int x, int l, int r, int d) {
    node[x].l = l;
    node[x].r = r;
    node[x].d = d;
    if (l == r) {
        node[x].v = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid, d ^ 1);
    build(rc(x), mid + 1, r, d ^ 1);
    pushUp(x);
}

void update(int x, int pos, int v) {
    if (node[x].l == node[x].r) {
        node[x].v = v;
        return;
    }
    int mid = (node[x].l + node[x].r) / 2;
    if (pos <= mid) {
        update(lc(x), pos, v);
    } else {
        update(rc(x), pos, v);
    }
    pushUp(x);
}

int main() {
    int p, b;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= (1 << n); ++i) {
        scanf("%d", &a[i]);
    }
    build(1, 1, (1 << n), n & 1);
    while (m--) {
        scanf("%d%d", &p, &b);
        update(1, p, b);
        printf("%d\n", node[1].v);
    }
    return 0;
}
