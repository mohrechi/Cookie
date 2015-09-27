#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

int n, m, a[MAXN];

struct Edge {
    int u, v, w;
    bool operator <(const Edge &edge) const {
        return w > edge.w;
    }
} edge[MAXN];

int parent[MAXN], cnt[MAXN];

void init() {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        cnt[i] = 1;
    }
}

int find(int x) {
    if (x == parent[x]) {
        return x;
    }
    return parent[x] = find(parent[x]);
}

void combine(int x, int y) {
    x = find(x);
    y = find(y);
    parent[x] = y;
    cnt[y] += cnt[x];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &edge[i].u, &edge[i].v);
        edge[i].w = min(a[edge[i].u], a[edge[i].v]);
    }
    sort(edge, edge + m);
    init();
    double ans = 0.0;
    for (int i = 0; i < m; ++i) {
        int u = find(edge[i].u);
        int v = find(edge[i].v);
        if (u != v) {
            ans += (double)edge[i].w * cnt[u] * cnt[v];
            combine(u, v);
        }
    }
    double total = 0.5 * n * (n - 1);
    printf("%.10f\n", ans / total);
    return 0;
}
