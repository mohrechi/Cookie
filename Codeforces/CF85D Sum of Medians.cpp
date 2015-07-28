#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n;

struct Query {
    char s[4];
    int x;
} queries[MAXN];

struct Tree {
    int l, r;
    int lazy, shift, num;
    long long sum[5];
} tree[MAXN * 3];

inline int lc(int x) {
    return x * 2;
}

inline int rc(int x) {
    return lc(x) + 1;
}

void pushUp(int x) {
    tree[x].num = tree[lc(x)].num + tree[rc(x)].num;
    for (int i = 0; i < 5; ++i) {
        int pos = (i - tree[x].shift + 5) % 5;
        int posL = (i - tree[lc(x)].shift + 5) % 5;
        int posR = (i - tree[rc(x)].shift + 5) % 5;
        tree[x].sum[pos] = tree[lc(x)].sum[posL] + tree[rc(x)].sum[posR];
    }
}

void pushDown(int x) {
    if (tree[x].lazy) {
        (tree[lc(x)].shift += tree[x].lazy) %= 5;
        (tree[rc(x)].shift += tree[x].lazy) %= 5;
        (tree[lc(x)].lazy += tree[x].lazy) %= 5;
        (tree[rc(x)].lazy += tree[x].lazy) %= 5;
        tree[x].lazy = 0;
    }
}

void build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].shift = 0;
    tree[x].lazy = 0;
    tree[x].num = 0;
    memset(tree[x].sum, 0, sizeof(tree[x].sum));
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void updateShift(int x, int l, int r, int shift) {
    if (tree[x].l == l && tree[x].r == r) {
        (tree[x].shift += shift + 5) %= 5;
        (tree[x].lazy += shift + 5) %= 5;
        return;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (r <= mid) {
        updateShift(lc(x), l, r, shift);
    } else if (l > mid) {
        updateShift(rc(x), l, r, shift);
    } else {
        updateShift(lc(x), l, mid, shift);
        updateShift(rc(x), mid + 1, r, shift);
    }
    pushUp(x);
}

void updateValue(int x, int pos, int shift, int val) {
    if (tree[x].l == tree[x].r) {
        pos = (shift - tree[x].shift + 5) % 5;
        tree[x].sum[pos] = val;
        tree[x].num = val > 0;
        return;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (pos <= mid) {
        updateValue(lc(x), pos, shift, val);
    } else {
        updateValue(rc(x), pos, shift, val);
    }
    pushUp(x);
}

int queryLess(int x, int l, int r) {
    if (tree[x].l == l && tree[x].r == r) {
        return tree[x].num;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (r <= mid) {
        return queryLess(lc(x), l, r);
    }
    if (l > mid) {
        return queryLess(rc(x), l, r);
    }
    return queryLess(lc(x), l, mid) + queryLess(rc(x), mid + 1, r);
}

long long querySum() {
    int pos = (2 - tree[1].shift + 5) % 5;
    return tree[1].sum[pos];
}

int main() {
    scanf("%d", &n);
    set<int> vals;
    map<int, int> idx;
    for (int i = 0; i < n; ++i) {
        scanf("%s", queries[i].s);
        if (queries[i].s[0] != 's') {
            scanf("%d", &queries[i].x);
            if (queries[i].s[0] == 'a') {
                vals.insert(queries[i].x);
            }
        }
    }
    int id = 0;
    for (auto val : vals) {
        idx[val] = ++id;
    }
    int m = (int) vals.size();
    build(1, 0, m + 1);
    for (int i = 0; i < n; ++i) {
        int x = queries[i].x;
        switch (queries[i].s[0]) {
        case 'a':
            updateValue(1, idx[x], queryLess(1, 0, idx[x] - 1) % 5, x);
            updateShift(1, idx[x] + 1, m + 1, 1);
            break;
        case 'd':
            updateValue(1, idx[x], queryLess(1, 0, idx[x] - 1) % 5, 0);
            updateShift(1, idx[x] + 1, m + 1, -1);
            break;
        case 's':
            printf("%I64d\n", querySum());
            break;
        }
    }
    return 0;
}
