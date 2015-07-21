#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;

struct Node {
    int numL, numR, sum;

    friend Node operator +(const Node &a, const Node &b) {
        Node c;
        int paired = min(a.numL, b.numR);
        c.numL = a.numL + b.numL - paired;
        c.numR = a.numR + b.numR - paired;
        c.sum = a.sum + b.sum + paired;
        return c;
    }
};

struct TreeNode {
    int l, r;
    Node val;
} tree[MAXN * 3];

char s[MAXN];

inline int lc(int x) {
    return x << 1;
}

inline int rc(int x) {
    return lc(x) + 1;
}

void build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].val.numL = s[l - 1] == '(';
        tree[x].val.numR = s[r - 1] == ')';
        tree[x].val.sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
    tree[x].val = tree[lc(x)].val + tree[rc(x)].val;
}

Node query(int x, int l, int r) {
    if (tree[x].l == l and tree[x].r == r) {
        return tree[x].val;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid) {
        return query(lc(x), l, r);
    }
    if (l > mid) {
        return query(rc(x), l, r);
    }
    return query(lc(x), l, mid) + query(rc(x), mid + 1, r);
}

int main() {
    int q, l, r;
    gets(s);
    build(1, 1, strlen(s));
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &l, &r);
        printf("%d\n", query(1, l, r).sum << 1);
    }
    return 0;
}
