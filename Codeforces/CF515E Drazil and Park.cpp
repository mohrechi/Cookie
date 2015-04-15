#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m, a, b;
long long d[MAXN * 2], h[MAXN * 2];

long long sum[MAXN * 2];

struct Node {
    long long maxVal, maxL, maxR;
    friend ostream& operator <<(ostream& out, const Node& node) {
        out << node.maxVal;
        return out;
    }
};

struct TreeNode {
    int l, r;
    Node val;
} tree[MAXN * 2 * 3];

inline int lchild(const int &x) {
    return x << 1;
}

inline int rchild(const int &x) {
    return lchild(x) + 1;
}

void buildTree(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        tree[x].val.maxVal = 0;
        tree[x].val.maxL = 2 * h[l] - sum[l - 1];
        tree[x].val.maxR = 2 * h[r] + sum[r - 1];
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(lchild(x), l, mid);
    buildTree(rchild(x), mid + 1, r);
    tree[x].val.maxL = max(tree[lchild(x)].val.maxL, tree[rchild(x)].val.maxL);
    tree[x].val.maxR = max(tree[lchild(x)].val.maxR, tree[rchild(x)].val.maxR);
    tree[x].val.maxVal = max(tree[lchild(x)].val.maxL + tree[rchild(x)].val.maxR,
                             max(tree[lchild(x)].val.maxVal, tree[rchild(x)].val.maxVal));
}

Node queryTree(int x, int l, int r) {
    if (tree[x].l == l && tree[x].r == r) {
        return tree[x].val;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid) {
        return queryTree(lchild(x), l, r);
    }
    if (l > mid) {
        return queryTree(rchild(x), l, r);
    }
    Node left = queryTree(lchild(x), l, mid);
    Node right = queryTree(rchild(x), mid + 1, r);
    Node node;
    node.maxL = max(left.maxL, right.maxL);
    node.maxR = max(left.maxR, right.maxR);
    node.maxVal = max(left.maxL + right.maxR, max(left.maxVal, right.maxVal));
    return node;
}

int main() {
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            cin >> d[i];
            d[n + i] = d[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> h[i];
            h[n + i] = h[i];
        }
        sum[1] = d[1];
        for (int i = 2; i < (n << 1); ++i) {
            sum[i] = sum[i - 1] + d[i];
        }
        buildTree(1, 1, n << 1);
        while (m--) {
            cin >> a >> b;
            if (a <= b) {
                cout << queryTree(1, b + 1, a + n - 1) << endl;
            } else {
                cout << queryTree(1, b + 1, a - 1) << endl;
            }
        }
    }
    return 0;
}
