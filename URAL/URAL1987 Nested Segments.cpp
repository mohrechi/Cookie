#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 1e5 + 10;
const int MAXK = MAXN * 2 + MAXM;

struct TreeNode {
    int l, r;
    int lazy;
} tree[MAXK * 4];

void buildTree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lazy = (x == 1 ? -1 : 0);
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(x << 1, l, mid);
    buildTree((x << 1) + 1, mid + 1, r);
}

void pushDown(int x) {
    if (tree[x].lazy) {
        tree[x << 1].lazy = tree[x].lazy;
        tree[(x << 1) + 1].lazy = tree[x].lazy;
        tree[x].lazy = 0;
    }
}

void updateTree(int x, int l, int r, int value) {
    if (tree[x].l == l && tree[x].r == r) {
        tree[x].lazy = value;
        return;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid) {
        updateTree(x << 1, l, r, value);
    } else if (l > mid) {
        updateTree((x << 1) + 1, l, r, value);
    } else {
        updateTree(x << 1, l, mid, value);
        updateTree((x << 1) + 1, mid + 1, r, value);
    }
}

int queryTree(int x, int pos) {
    if (tree[x].lazy) {
        return tree[x].lazy;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid) {
        return queryTree(x << 1, pos);
    }
    return queryTree((x << 1) + 1, pos);
}

int n, m;
int a[MAXN], b[MAXN], c[MAXM];
int values[MAXK], valueNum;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i], &b[i]);
        values[valueNum++] = a[i];
        values[valueNum++] = b[i];
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d", &c[i]);
        values[valueNum++] = c[i];
    }
    sort(values, values + valueNum);
    map<int, int> indexes;
    int index = 0;
    indexes[values[0]] = ++index;
    for (int i = 1; i < valueNum; ++i) {
        if (values[i - 1] != values[i]) {
            indexes[values[i]] = ++index;
        }
    }
    buildTree(1, 1, index);
    for (int i = 0; i < n; ++i) {
        updateTree(1, indexes[a[i]], indexes[b[i]], i + 1);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", queryTree(1, indexes[c[i]]));
    }
    return 0;
}
