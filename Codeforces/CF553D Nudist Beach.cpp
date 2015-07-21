#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000 + 10;
const int MAXM = 100000 + 10;

int n, m, k;
bool f[MAXN];

struct Edge {
    int v, next;
} edge[MAXM * 2];
int head[MAXN], edgeNum = 1;
int degree[MAXN], alley[MAXN];

inline void addEdgeSub(int u, int v) {
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v) {
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

struct Node {
    int i, a;
    bool operator <(const Node& node) const {
        long long l = 1LL * a * degree[node.i];
        long long r = 1LL * node.a * degree[i];
        if (l == r) {
            return i < node.i;
        }
        return l < r;
    }
};

int path[MAXN];
bool visit[MAXN];

int main() {
    int fff, u, v;
    scanf("%d%d%d", &n, &m, &k);
    while (k--) {
        scanf("%d", &fff);
        f[fff] = true;
    }
    while (m--) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        ++degree[u];
        ++degree[v];
        if (!f[u]) ++alley[v];
        if (!f[v]) ++alley[u];
    }
    set<Node> q;
    m = 0;
    for (int i = 1; i <= n; ++i) {
        if (f[i]) {
            visit[i] = true;
        } else {
            q.insert({i, alley[i]});
            ++m;
        }
    }
    int a = -1, d = 1;
    int idx = 0, ans = 0;
    while (q.size() > 0) {
        Node u = *q.begin();
        q.erase(u);
        visit[u.i] = true;
        path[++idx] = u.i;
        if (1LL * u.a * d > 1LL * degree[u.i] * a) {
            d = degree[u.i];
            a = u.a;
            ans = idx;
        }
        for (int i = head[u.i]; i != 0; i = edge[i].next) {
            int v = edge[i].v;
            if (not visit[v]) {
                q.erase({v, alley[v]});
                --alley[v];
                q.insert({v, alley[v]});
            }
        }
    }
    printf("%d\n", m - ans + 1);
    for (int i = ans; i <= m; ++i) {
        printf("%d ", path[i]);
    }
    putchar('\n');
    return 0;
}
