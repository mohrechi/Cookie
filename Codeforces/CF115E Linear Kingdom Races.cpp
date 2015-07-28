#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int n, m;
int cost[MAXN];
struct Race {
    int l, r, profit;
    bool operator <(const Race &race) const {
        if (r == race.r) {
            return l < race.l;
        }
        return r < race.r;
    }
} race[MAXN];

struct Tree {
    int l, r;
    long long lazy, maxVal;
} tree[MAXN * 3];

long long dp[MAXN];

inline int lc(int x) {
    return x * 2;
}

inline int rc(int x) {
    return lc(x) + 1;
}

inline void pushUp(int x) {
    tree[x].maxVal = max(tree[lc(x)].maxVal, tree[rc(x)].maxVal);
}

void pushDown(int x) {
    if (tree[x].lazy) {
        tree[lc(x)].lazy += tree[x].lazy;
        tree[rc(x)].lazy += tree[x].lazy;
        tree[lc(x)].maxVal += tree[x].lazy;
        tree[rc(x)].maxVal += tree[x].lazy;
        tree[x].lazy = 0;
    }
}

void build(int x, int l, int r) {
    tree[x].l = l;
    tree[x].r = r;
    tree[x].lazy = 0;
    tree[x].maxVal = 0;
    if (tree[x].l == tree[x].r) {
        return;
    }
    int mid = (l + r) / 2;
    build(lc(x), l, mid);
    build(rc(x), mid + 1, r);
}

void update(int x, int l, int r, long long val) {
    if (tree[x].l == l && tree[x].r == r) {
        tree[x].lazy += val;
        tree[x].maxVal += val;
        return;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) / 2;
    if (r <= mid) {
        update(lc(x), l, r, val);
    } else if (l > mid) {
        update(rc(x), l, r, val);
    } else {
        update(lc(x), l, mid, val);
        update(rc(x), mid + 1, r, val);
    }
    pushUp(x);
}

inline long long query() {
    return tree[1].maxVal;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &cost[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &race[i].l, &race[i].r, &race[i].profit);
    }
    sort(race, race + m);
    int idx = 0;
    build(1, 0, n);
    for (int i = 1; i <= n; ++i) {
        update(1, 0, i - 1, -cost[i]);
        while (idx < m && race[idx].r <= i) {
            update(1, 0, race[idx].l - 1, race[idx].profit);
            ++idx;
        }
        dp[i] = max(dp[i - 1], query());
        update(1, i, i, dp[i]);
    }
    cout << dp[n] << endl;
    return 0;
}
