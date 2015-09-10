#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n, m, s[MAXN];

struct Node {
    int minVal;
    int divisor;
    int cnt;
};

struct TreeNode {
    int l, r;
    Node val;
} node[MAXN * 3];

inline int lc(int x) {
    return x * 2;
}

inline int rc(int x) {
    return lc(x) + 1;
}

inline Node pushUp(const Node &a, const Node &b) {
    Node c;
    if (a.minVal < b.minVal) {
        c.minVal = a.minVal;
        c.cnt = a.cnt;
    } else if (a.minVal > b.minVal) {
        c.minVal = b.minVal;
        c.cnt = b.cnt;
    } else {
        c.minVal = a.minVal;
        c.cnt = a.cnt + b.cnt;
    }
    c.divisor = __gcd(a.divisor, b.divisor);
    return c;
}

inline void pushUp(int x) {
    node[x].val = pushUp(node[lc(x)].val, node[rc(x)].val);
}

void build(int x, int l, int r) {
    node[x].l = l;
    node[x].r = r;
    if (l == r) {
        node[x].val = {s[l], s[l], 1};
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
    pushUp(x);
}

Node query(int x, int l, int r) {
    if (node[x].l == l && node[x].r == r) {
        return node[x].val;
    }
    int mid = (node[x].l + node[x].r) / 2;
    if (r <= mid) {
        return query(lc(x), l, r);
    }
    if (l > mid) {
        return query(rc(x), l, r);
    }
    return pushUp(query(lc(x), l, mid), query(rc(x), mid + 1, r));
}

int main() {
    int l, r;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &s[i]);
    }
    build(1, 1, n);
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &l, &r);
        auto val = query(1, l, r);
        int num = r - l + 1;
        if (val.minVal == val.divisor) {
            num -= val.cnt;
        }
        printf("%d\n", num);
    }
    return 0;
}
