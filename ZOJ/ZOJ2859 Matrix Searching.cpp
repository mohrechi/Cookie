#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300 + 10;

int n, a[MAXN][MAXN];

struct QuadTreeNode {
    int l, r, t, b;
    int minVal;
} tree[MAXN * MAXN * 4];

inline int ltc(int x) { return x * 4 - 2; }
inline int rtc(int x) { return ltc(x) + 1; }
inline int lbc(int x) { return rtc(x) + 1; }
inline int rbc(int x) { return lbc(x) + 1; }

void build(int x, int l, int r, int t, int b) {
    tree[x] = {l, r, t, b, 0};
    if (l == r && t == b) {
        tree[x].minVal = a[l][t];
        return;
    }
    int midH = (l + r) / 2;
    int midV = (t + b) / 2;
    if (l == r) {
        build(ltc(x), l, r, t, midV);
        build(rtc(x), l, r, t, midV);
        build(lbc(x), l, r, midV + 1, b);
        build(rbc(x), l, r, midV + 1, b);
    } else if (t == b) {
        build(ltc(x), l, midH, t, b);
        build(rtc(x), midH + 1, r, t, b);
        build(lbc(x), l, midH, t, b);
        build(rbc(x), midH + 1, r, t, b);
    } else {
        build(ltc(x), l, midH, t, midV);
        build(rtc(x), midH + 1, r, t, midV);
        build(lbc(x), l, midH, midV + 1, b);
        build(rbc(x), midH + 1, r, midV + 1, b);
    }
    tree[x].minVal = min(min(tree[ltc(x)].minVal, tree[rtc(x)].minVal),
                         min(tree[lbc(x)].minVal, tree[rbc(x)].minVal));
}

int query(int x, int l, int r, int t, int b) {
    if (tree[x].l == l && tree[x].r == r && tree[x].b == b && tree[x].t == t) {
        return tree[x].minVal;
    }
    int midH = (tree[x].l + tree[x].r) / 2;
    int midV = (tree[x].t + tree[x].b) / 2;
    if (r <= midH) {
        if (b <= midV) {
            return query(ltc(x), l, r, t, b);
        }
        if (t > midV) {
            return query(lbc(x), l, r, t, b);
        }
        return min(query(ltc(x), l, r, t, midV), query(lbc(x), l, r, midV + 1, b));
    }
    if (l > midH) {
        if (b <= midV) {
            return query(rtc(x), l, r, t, b);
        }
        if (t > midV) {
            return query(rbc(x), l, r, t, b);
        }
        return min(query(rtc(x), l, r, t, midV), query(rbc(x), l, r, midV + 1, b));
    }
    if (b <= midV) {
        return min(query(ltc(x), l, midH, t, b), query(rtc(x), midH + 1, r, t, b));
    }
    if (t > midV) {
        return min(query(lbc(x), l, midH, t, b), query(rbc(x), midH + 1, r, t, b));
    }
    return min(min(query(ltc(x), l, midH, t, midV), query(rtc(x), midH + 1, r, t, midV)),
               min(query(lbc(x), l, midH, midV + 1, b), query(rbc(x), midH + 1, r, midV + 1, b)));
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        build(1, 1, n, 1, n);
        int q, l, t, r, b;
        scanf("%d", &q);
        while (q--) {
            scanf("%d%d%d%d", &l, &t, &r, &b);
            printf("%d\n", query(1, l, r, t, b));
        }
    }
    return 0;
}
