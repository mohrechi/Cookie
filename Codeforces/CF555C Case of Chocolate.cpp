#include <bits/stdc++.h>
using namespace std;
const int MAXQ = 2e5 + 10;
const int MAXM = MAXQ * 4 * 3;

class SegmentTree {
public:
    void build(int x, int l, int r) {
        tree[x].l = l;
        tree[x].r = r;
        tree[x].val = 0;
        if (l == r) {
            return ;
        }
        int mid = (l + r) >> 1;
        build(lc(x), l, mid);
        build(rc(x), mid + 1, r);
    }
    void update(int x, int l, int r, int val) {
        if (l > r) {
            return;
        }
        if (tree[x].l == l and tree[x].r == r) {
            tree[x].val = max(tree[x].val, val);
            return;
        }
        pushDown(x);
        int mid = (tree[x].l + tree[x].r) >> 1;
        if (r <= mid) {
            update(lc(x), l, r, val);
        } else if (l > mid) {
            update(rc(x), l, r, val);
        } else {
            update(lc(x), l, mid, val);
            update(rc(x), mid + 1, r, val);
        }
    }
    int query(int x, int pos) {
        if (tree[x].l == tree[x].r) {
            return tree[x].val;
        }
        pushDown(x);
        int mid = (tree[x].l + tree[x].r) >> 1;
        if (pos <= mid) {
            return query(lc(x), pos);
        }
        return query(rc(x), pos);
    }
private:
    struct TreeNode {
        int l, r;
        int val;
    } tree[MAXM];
    inline int lc(int x) {
        return x << 1;
    }
    inline int rc(int x) {
        return lc(x) + 1;
    }
    void pushDown(int x) {
        if (tree[x].val) {
            tree[lc(x)].val = max(tree[lc(x)].val, tree[x].val);
            tree[rc(x)].val = max(tree[rc(x)].val, tree[x].val);
            tree[x].val = 0;
        }
    }
} horizon, vertical;

int n, q;
int x[MAXQ], y[MAXQ];
char dir[MAXQ];

int main() {
    set<int> s;
    scanf("%d%d", &n, &q);
    s.insert(1);
    s.insert(n);
    for (int i = 0; i < q; ++i) {
        scanf("%d%d%s", &x[i], &y[i], dir + i);
        s.insert(x[i]);
        s.insert(y[i]);
        s.insert(x[i] + 1);
        s.insert(y[i] + 1);
    }
    map<int, int> idx;
    map<int, int> val;
    int i = 0, m = s.size();
    for (auto a : s) {
        idx[a] = ++i;
        val[i] = a;
    }
    horizon.build(1, 1, m);
    vertical.build(1, 1, m);
    for (int i = 0; i < q; ++i) {
        if (dir[i] == 'U') {
            int border = horizon.query(1, idx[x[i]]);
            horizon.update(1, idx[x[i]], idx[x[i]], idx[y[i]]);
            vertical.update(1, border + 1, idx[y[i]], idx[x[i]]);
            printf("%d\n", y[i] - val[border]);
        } else {
            int border = vertical.query(1, idx[y[i]]);
            vertical.update(1, idx[y[i]], idx[y[i]], idx[x[i]]);
            horizon.update(1, border + 1, idx[x[i]], idx[y[i]]);
            printf("%d\n", x[i] - val[border]);
        }
    }
    return 0;
}
