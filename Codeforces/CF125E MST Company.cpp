#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000 + 10;
const int MAXM = 1e5 + 10;

int n, m, k;
double extra;
struct Edge {
    int a, b, w, idx;
    inline bool cap() const {
        return a == 1 || b == 1;
    }
    inline double getW() const {
        if (cap()) {
            return w + extra;
        }
        return w;
    }
    bool operator <(const Edge &edge) const {
        return getW() < edge.getW();
    }
} edge[MAXM];

int parent[MAXN];

void init() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
}

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void combine(int x, int y) {
    parent[find(x)] = find(y);
}

int choose[MAXN];

int solve(bool flag = false) {
    int ret = 0, num = 0;
    init();
    sort(edge + 1, edge + 1 + m);
    for (int i = 1; i <= m; ++i) {
        if (find(edge[i].a) != find(edge[i].b)) {
            if (flag && edge[i].cap() && ret == k) {
                continue;
            }
            combine(edge[i].a, edge[i].b);
            if (edge[i].cap()) {
                ++ret;
            }
            choose[++num] = edge[i].idx;
        }
    }
    if (num + 1 < n) {
        return -1;
    }
    return ret;
}

int main() {
    int a, b, w;
    scanf("%d%d%d", &n, &m, &k);
    if (n > 1 && k == 0) {
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d", &a, &b, &w);
        edge[i].idx = i;
        edge[i].a = a;
        edge[i].b = b;
        edge[i].w = w;
    }
    double l = -1e5, r = 1e5;
    int capNum = 1e6;
    double ans = 0.0;
    while (r - l > 1e-6) {
        double mid = (l + r) / 2;
        extra = mid;
        capNum = solve();
        if (capNum == -1 || capNum == k) {
            break;
        }
        if (capNum < k) {
            r = mid;
        } else {
            ans = min(ans, mid);
            l = mid;
        }
    }
    if (capNum == -1) {
        cout << -1 << endl;
    } else {
        if (capNum != k) {
            extra = ans;
            capNum = solve(true);
        }
        cout << n - 1 << endl;
        for (int i = 1; i < n; ++i) {
            printf("%d ", choose[i]);
        }
        putchar('\n');
    }
    return 0;
}
