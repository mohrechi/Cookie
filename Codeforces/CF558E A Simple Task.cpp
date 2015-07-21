#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, q;
char s[MAXN];

class SegmentTree {
public:
    void build(int x, int l, int r, char c) {
        tree[x].l = l;
        tree[x].r = r;
        tree[x].reset = false;
        tree[x].reverse = false;
        if (l == r) {
            tree[x].num = s[l] == c;
            return;
        }
        int mid = (l + r) / 2;
        build(lc(x), l, mid, c);
        build(rc(x), mid + 1, r, c);
        pushUp(x);
    }
    void update(int x, int l, int r, int shift, int num, bool reverse) {
        if (tree[x].l == l and tree[x].r == r) {
            tree[x].num = num;
            tree[x].reset = true;
            tree[x].shift = shift;
            tree[x].reverse = reverse;
            return;
        }
        pushDown(x);
        int mid = (tree[x].l + tree[x].r) / 2;
        if (reverse) {
            int lenR = r - mid;
            if (r <= mid) {
                update(lc(x), l, r, shift, num, reverse);
            } else if (l > mid) {
                update(rc(x), l, r, shift, num, reverse);
            } else {
                update(lc(x), l, mid, max(shift - lenR, 0), max(shift + num - max(shift, lenR), 0), reverse);
                update(rc(x), mid + 1, r, min(shift, lenR), min(num, max(0, lenR - shift)), reverse);
            }
        } else {
            int lenL = mid - l + 1;
            if (r <= mid) {
                update(lc(x), l, r, shift, num, reverse);
            } else if (l > mid) {
                update(rc(x), l, r, shift, num, reverse);
            } else {
                update(lc(x), l, mid, min(shift, lenL), min(num, max(0, lenL - shift)), reverse);
                update(rc(x), mid + 1, r, max(shift - lenL, 0), max(shift + num - max(shift, lenL), 0), reverse);
            }
        }
        pushUp(x);
    }
    bool query(int x, int pos) {
        if (tree[x].l == tree[x].r) {
            return tree[x].num == 1;
        }
        pushDown(x);
        int mid = (tree[x].l + tree[x].r) / 2;
        if (pos <= mid) {
            return query(lc(x), pos);
        }
        return query(rc(x), pos);
    }
    int query(int x, int l, int r) {
        if (tree[x].l == l and tree[x].r == r) {
            return tree[x].num;
        }
        pushDown(x);
        int mid = (tree[x].l + tree[x].r) / 2;
        if (r <= mid) {
            return query(lc(x), l, r);
        }
        if (l > mid) {
            return query(rc(x), l, r);
        }
        return query(lc(x), l, mid) + query(rc(x), mid + 1, r);
    }
private:
    struct TreeNode {
        int num, l, r;
        bool reset, reverse;
        int shift;
    } tree[MAXN * 3];
    inline int lc(int x) {
        return x * 2;
    }
    inline int rc(int x) {
        return lc(x) + 1;
    }
    inline void pushUp(int x) {
        tree[x].num = tree[lc(x)].num + tree[rc(x)].num;
    }
    inline void pushDown(int x) {
        if (tree[x].reset) {
            if (tree[x].reverse) {
                int lenR = tree[rc(x)].r - tree[rc(x)].l + 1;
                if (tree[x].shift + tree[x].num <= lenR) {
                    tree[rc(x)].num = tree[x].num;
                    tree[rc(x)].shift = tree[x].shift;
                    tree[lc(x)].num = 0;
                    tree[lc(x)].shift = 0;
                } else if (tree[x].shift > lenR) {
                    tree[rc(x)].num = 0;
                    tree[rc(x)].shift = lenR;
                    tree[lc(x)].num = tree[x].num;
                    tree[lc(x)].shift = tree[x].shift - lenR;
                } else {
                    tree[rc(x)].num = lenR - tree[x].shift;
                    tree[rc(x)].shift = tree[x].shift;
                    tree[lc(x)].num = tree[x].shift + tree[x].num - lenR;
                    tree[lc(x)].shift = 0;
                }
            } else {
                int lenL = tree[lc(x)].r - tree[lc(x)].l + 1;
                if (tree[x].shift + tree[x].num <= lenL) {
                    tree[lc(x)].num = tree[x].num;
                    tree[lc(x)].shift = tree[x].shift;
                    tree[rc(x)].num = 0;
                    tree[rc(x)].shift = 0;
                } else if (tree[x].shift > lenL) {
                    tree[lc(x)].num = 0;
                    tree[lc(x)].shift = lenL;
                    tree[rc(x)].num = tree[x].num;
                    tree[rc(x)].shift = tree[x].shift - lenL;
                } else {
                    tree[lc(x)].num = lenL - tree[x].shift;
                    tree[lc(x)].shift = tree[x].shift;
                    tree[rc(x)].num = tree[x].shift + tree[x].num - lenL;
                    tree[rc(x)].shift = 0;
                }
            }
            tree[lc(x)].reset = true;
            tree[rc(x)].reset = true;
            tree[lc(x)].reverse = tree[x].reverse;
            tree[rc(x)].reverse = tree[x].reverse;
            tree[x].reset = false;
        }
    }
} tree[26];

int main() {
    int l, r, k;
    scanf("%d%d", &n, &q);
    scanf("%s", s + 1);
    for (int i = 'a'; i <= 'z'; ++i) {
        tree[i - 'a'].build(1, 1, n, i);
    }
    while (q--) {
        scanf("%d%d%d", &l, &r, &k);
        for (int i = 0, shift = 0; i < 26; ++i) {
            int num = tree[i].query(1, l, r);
            tree[i].update(1, l, r, shift, num, k == 0);
            shift += num;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if (tree[j].query(1, i)) {
                s[i] = j + 'a';
                break;
            }
        }
    }
    puts(s + 1);
    return 0;
}
