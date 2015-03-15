#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1e5 + 10;
const int MOD = 1e9 + 7;

int n, m;
char input[MAXN];
__int64 factor[MAXN];

struct TreeNode {
    int l, r;
    int sum[2];
} tree[MAXN * 3];

void initFactor() {
    factor[0] = 1;
    for (int i = 1; i <= n; ++i) {
        factor[i] = (factor[i - 1] * 37) % MOD;
    }
}

inline int lchild(int x) {
    return x << 1;
}

inline int rchild(int x) {
    return lchild(x) + 1;
}

void pushUp(int x, bool reverse) {
    tree[x].sum[reverse] = (tree[lchild(x)].sum[reverse] + tree[rchild(x)].sum[reverse]) % MOD;
}

void buildTree(int x, int l, int r, bool reverse) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        char ch = reverse ? input[n - l + 1] : input[l];
        tree[x].sum[reverse] = (ch - 'a') * factor[l] % MOD;
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(lchild(x), l, mid, reverse);
    buildTree(rchild(x), mid + 1, r, reverse);
    pushUp(x, reverse);
}

void buildTree() {
    buildTree(1, 1, n, false);
    buildTree(1, 1, n, true);
}

void updateTree(int x, int pos, char ch, bool reverse) {
    if (tree[x].l == tree[x].r) {
        tree[x].sum[reverse] = (ch - 'a') * factor[pos] % MOD;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid) {
        updateTree(lchild(x), pos, ch, reverse);
    } else {
        updateTree(rchild(x), pos, ch, reverse);
    }
    pushUp(x, reverse);
}

void updateTree(int pos, char ch) {
    updateTree(1, pos, ch, false);
    updateTree(1, n - pos + 1, ch, true);
}

int queryTree(int x, int l, int r, bool reverse) {
    if (tree[x].l == l && tree[x].r == r) {
        return tree[x].sum[reverse];
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid) {
        return queryTree(lchild(x), l, r, reverse);
    }
    if (l > mid) {
        return queryTree(rchild(x), l, r, reverse);
    }
    return (queryTree(lchild(x), l, mid, reverse) + queryTree(rchild(x), mid + 1, r, reverse)) % MOD;
}

bool queryTree(int l, int r) {
    __int64 hash1 = queryTree(1, l, r, false);
    __int64 hash2 = queryTree(1, n - r + 1, n - l + 1, true);
    if (l < n - r + 1) {
        return hash1 * factor[(n - r + 1) - l] % MOD == hash2;
    } else if (l > n - r + 1) {
        return hash1 == hash2 * factor[l - (n - r + 1)] % MOD;
    }
    return hash1 == hash2;
}

int main() {
    int l, r;
    scanf("%s", input + 1);
    n = strlen(input + 1);
    initFactor();
    buildTree();
    scanf("%d", &m);
    while (m--) {
        scanf("%s", input);
        if (input[0] == 'p') {
            scanf("%d%d", &l, &r);
            puts(queryTree(l, r) ? "Yes" : "No");
        } else {
            scanf("%d%s", &l, input);
            updateTree(l, input[0]);
        }
    }
    return 0;
}
