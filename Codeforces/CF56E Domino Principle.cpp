#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n, ans[MAXN];
struct Domino {
    int x, h, idx, hit;
    bool operator <(const Domino& other) const {
        return x < other.x;
    }
} domino[MAXN];

struct SegmentTreeNode {
    int l, r, rightMost;
} tree[MAXN * 3];

inline int lc(int x) {
    return x << 1;
}

inline int rc(int x) {
    return lc(x) + 1;
}

int build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    if (l == r) {
        return tree[x].rightMost = l;
    }
    int mid = (l + r) >> 1;
    return tree[x].rightMost = max(build(lc(x), l, mid), build(rc(x), mid + 1, r));
}

void update(int x, int pos, int val) {
    tree[x].rightMost = max(tree[x].rightMost, val);
    if (tree[x].l == tree[x].r) {
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid) {
        update(lc(x), pos, val);
    } else {
        update(rc(x), pos, val);
    }
}

int query(int x, int l, int r) {
    if (tree[x].l == l && tree[x].r == r) {
        return tree[x].rightMost;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid) {
        return query(lc(x), l, r);
    }
    if (l > mid) {
        return query(rc(x), l, r);
    }
    return max(query(lc(x), l, mid), query(rc(x), mid + 1, r));
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> domino[i].x >> domino[i].h;
        domino[i].idx = i;
        domino[i].hit = 0;
    }
    sort(domino, domino + n);
    build(1, 0, n - 1);
    for (int i = n - 1; i >= 0; --i) {
        int l = i + 1, r = n - 1;
        int rightMost = i;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (domino[mid].x <= domino[i].x + domino[i].h - 1) {
                l = mid + 1;
                rightMost = max(rightMost, mid);
            } else {
                r = mid - 1;
            }
        }
        rightMost = query(1, i, rightMost);
        domino[i].hit = rightMost - i + 1;
        update(1, i, rightMost);
    }
    for (int i = 0; i < n; ++i) {
        ans[domino[i].idx] = domino[i].hit;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << ' ';
    }
    return 0;
}
