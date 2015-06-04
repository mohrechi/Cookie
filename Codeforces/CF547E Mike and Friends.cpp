#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 10;

char s[MAXN];
int x[MAXN], len[MAXN];

int suf[MAXN], rnk[MAXN], pre[MAXN];
int cnt[MAXN], rnkA[MAXN], rnkB[MAXN];

void initSuf(const char* s, int n, int m) {
    int* x = rnkA;
    for (int i = 0; i < n; ++i) x[i] = s[i];
    for (int i = 0; i < m; ++i) cnt[i] = 0;
    for (int i = 0; i < n; ++i) ++cnt[x[i]];
    for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) suf[--cnt[x[i]]] = i;
    int* y = rnkB;
    for (int k = 1; ; k <<= 1) {
        int j = 0;
        for (int i = n - k; i < n; ++i) y[j++] = i;
        for (int i = 0; i < n; ++i) if (suf[i] >= k) y[j++] = suf[i] - k;
        for (int i = 0; i < m; ++i) cnt[i] = 0;
        for (int i = 0; i < n; ++i) ++cnt[x[y[i]]];
        for (int i = 1; i < m; ++i) cnt[i] += cnt[i - 1];
        for (int i = n - 1; i >= 0; --i) suf[--cnt[x[y[i]]]] = y[i];
        swap(x, y);
        m = 1;
        x[suf[0]] = 0;
        for (int i = 1; i < n; ++i) {
            int a = suf[i];
            int b = suf[i - 1];
            int c = a + k >= n ? -1 : y[a + k];
            int d = b + k >= n ? -1 : y[b + k];
            a = y[a];
            b = y[b];
            x[suf[i]] = (a == b and c == d) ? m - 1 : m++;
        }
        if (m >= n) break;
    }
}

void initPre(const char* s, int n) {
    int h = 0;
    for (int i = 0; i < n; ++i) rnk[suf[i]] = i;
    for (int i = 0; i < n; ++i) {
        if (rnk[i] == 0) continue;
        if (h > 0) --h;
        int j = suf[rnk[i] - 1];
        while (s[i + h] == s[j + h]) ++h;
        pre[rnk[i]] = h;
    }
}

int rlog[MAXN], rmin[19][MAXN];

void initLog() {
    rlog[0] = -1;
    for (int i = 1; i < MAXN; ++i) {
        rlog[i] = rlog[i - 1];
        if ((i & (i - 1)) == 0) {
            ++rlog[i];
        }
    }
}

void initRMQ(int n) {
    for (int i = 1; i <= n; ++i) {
        rmin[0][i] = pre[i];
    }
    for (int i = 1; i <= rlog[n]; ++i) {
        int m = n - (1 << i) + 1;
        for (int j = 1; j <= m; ++j) {
            rmin[i][j] = min(rmin[i - 1][j], rmin[i - 1][j + (1 << (i - 1))]);
        }
    }
}

int queryRMQ(int a, int b) {
    if (a == b) {
        return MAXN;
    }
    if (a > b) {
        swap(a, b);
    }
    ++a;
    int t = rlog[b - a + 1];
    return min(rmin[t][a], rmin[t][b - (1 << t) + 1]);
}

struct TreeNode {
    TreeNode *lc, *rc;
    int t, sum;
} head[MAXN];

void buildTree(TreeNode* node, int l, int r) {
    node->t = 0;
    node->sum = 0;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    node->lc = new TreeNode();
    node->rc = new TreeNode();
    buildTree(node->lc, l, mid);
    buildTree(node->rc, mid + 1, r);
}

inline void buildTree(int n) {
    buildTree(&head[0], 0, n - 1);
}

void updateTree(TreeNode* node, int tl, int tr, int t, int pos) {
    if (tl == tr) {
        ++node->sum;
        return;
    }
    int mid = (tl + tr) >> 1;
    if (pos <= mid) {
        if (node->lc->t < t) {
            TreeNode* c = new TreeNode();
            *c = *node->lc;
            node->lc = c;
        }
        updateTree(node->lc, tl, mid, t, pos);
    } else {
        if (node->rc->t < t) {
            TreeNode* c = new TreeNode();
            *c = *node->rc;
            node->rc = c;
        }
        updateTree(node->rc, mid + 1, tr, t, pos);
    }
    node->sum = node->lc->sum + node->rc->sum;
}

inline void updateTree(int t, int n, int pos) {
    if (head[t].t == 0) {
        head[t] = head[t - 1];
        head[t].t = t;
    }
    updateTree(&head[t], 0, n - 1, t, pos);
}

int queryTree(TreeNode* lnode, TreeNode* rnode, int tl, int tr, int l, int r) {
    if (tl == l and tr == r) {
        return rnode->sum - lnode->sum;
    }
    int mid = (tl + tr) >> 1;
    if (r <= mid) {
        return queryTree(lnode->lc, rnode->lc, tl, mid, l, r);
    }
    if (l > mid) {
        return queryTree(lnode->rc, rnode->rc, mid + 1, tr, l, r);
    }
    return queryTree(lnode->lc, rnode->lc, tl, mid, l, mid) +
           queryTree(lnode->rc, rnode->rc, mid + 1, tr, mid + 1, r);
}

inline int queryTree(int n, int t1, int t2, int l, int r) {
    return queryTree(&head[t1], &head[t2], 0, n - 1, l, r);
}

int main() {
    int n, m, q;
    int l, r, k;
    initLog();
    scanf("%d%d", &n, &q);
    m = 0;
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            s[m++] = ' ';
        }
        scanf("%s", s + m);
        len[i] = strlen(s + m);
        x[i] = m;
        m += len[i];
    }
    initSuf(s, m, 0x7f);
    initPre(s, m);
    initRMQ(m);
    buildTree(m);
    for (int i = 0, t = 1; i < m; ++i) {
        if (s[i] == ' ') {
            ++t;
        } else {
            updateTree(t, m, rnk[i]);
        }
    }
    while (q--) {
        scanf("%d%d%d", &l, &r, &k);
        int pos = rnk[x[k]];
        int a = pos, b = pos, ll, rr;
        ll = 0, rr = pos;
        while (ll <= rr) {
            int mid = (ll + rr) >> 1;
            if (queryRMQ(mid, pos) >= len[k]) {
                rr = mid - 1;
                a = min(a, mid);
            } else {
                ll = mid + 1;
            }
        }
        ll = pos, rr = m;
        while (ll <= rr) {
            int mid = (ll + rr) >> 1;
            if (queryRMQ(pos, mid) >= len[k]) {
                ll = mid + 1;
                b = max(b, mid);
            } else {
                rr = mid - 1;
            }
        }
        printf("%d\n", queryTree(m, l - 1, r, a, b));
    }
    return 0;
}
