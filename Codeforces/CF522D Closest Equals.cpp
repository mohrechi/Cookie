#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 10;

int n, m, a[MAXN];

struct TreeNode {
    int l, r, val;
} tree[MAXN * 3];

struct Query {
    int l, r, idx;
    bool operator <(const Query &query) const {
        return r < query.r;
    }
} q[MAXN];

int ans[MAXN];

inline int lc(int x) { return x * 2; }
inline int rc(int x) { return lc(x) + 1; }

void build(int x, int l, int r) {
    tree[x] = {l, r, MAXN};
    if (l == r) {
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void update(int x, int pos, int val) {
    tree[x].val = min(tree[x].val, val);
    if (tree[x].l == tree[x].r) {
        return;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (pos <= mid) {
        update(lc(x), pos, val);
    } else {
        update(rc(x), pos, val);
    }
}

int query(int x, int l, int r) {
    if (tree[x].l == l && tree[x].r == r) {
        return tree[x].val;
    }
    int mid = (tree[x].l + tree[x].r) / 2;
    if (r <= mid) {
        return query(lc(x), l, r);
    }
    if (l > mid) {
        return query(rc(x), l, r);
    }
    return min(query(lc(x), l, mid), query(rc(x), mid + 1, r));
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        q[i].idx = i;
        scanf("%d%d", &q[i].l, &q[i].r);
    }
    sort(q, q + m);
    build(1, 1, n);
    map<int, int> last;
    for (int i = 0, j = 0; i < m; ++i) {
        for (; j <= q[i].r; ++j) {
            if (last.find(a[j]) != last.end()) {
                int lastIdx = last[a[j]];
                update(1, lastIdx, j - lastIdx);
            }
            last[a[j]] = j;
        }
        ans[q[i].idx] = query(1, q[i].l, q[i].r);
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i] == MAXN ? -1 : ans[i]);
    }
    return 0;
}
