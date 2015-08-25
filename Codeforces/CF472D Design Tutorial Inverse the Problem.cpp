#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 10;

int n, m, d[MAXN][MAXN];

struct Node {
    int u, v, d;
    bool operator <(const Node &edge) const {
        return d < edge.d;
    }
} node[MAXN * MAXN];

int belong[MAXN];

void init() {
    for (int i = 1; i <= n; ++i) {
        belong[i] = i;
    }
}

int find(int x) {
    if (x == belong[x]) {
        return x;
    }
    return belong[x] = find(belong[x]);
}

inline void combine(int x, int y) {
    belong[find(x)] = find(y);
}

struct Edge {
    int v, w, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w) {
    edge[edgeNum] = {v, w, head[u]};
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int w) {
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, w);
}

int parent[MAXN][20], depth[MAXN];
long long dist[MAXN];

void dfs(int u, int p, long long di, int de) {
    dist[u] = di;
    depth[u] = de;
    parent[u][0] = p;
    for (int i = 1; parent[u][i - 1] != 0; ++i) {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int& v = edge[i].v;
        if (v != p) {
            int& w = edge[i].w;
            dfs(v, u, di + w, de + 1);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    for (int i = 19; depth[u] != depth[v]; --i) {
        if (depth[parent[u][i]] >= depth[v]) {
            u = parent[u][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 19; parent[u][0] != parent[v][0]; --i) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

long long calcDist(int u, int v) {
    return dist[u] + dist[v] - dist[lca(u, v)] * 2;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &d[i][j]);
            if (i < j) {
                node[m++] = {i, j, d[i][j]};
            }
        }
    }
    bool valid = true;
    for (int i = 1; i <= n && valid; ++i) {
        if (d[i][i] > 0) {
            valid = false;
        }
        for (int j = i + 1; j <= n; ++j) {
            if (d[i][j] == 0 || d[i][j] != d[j][i]) {
                valid = false;
            }
        }
    }
    if (!valid) {
        puts("NO");
        return 0;
    }
    sort(node, node + m);
    int conn = n - 1;
    init();
    clearEdge();
    for (int i = 0; i < m && conn; ++i) {
        int& u = node[i].u;
        int& v = node[i].v;
        if (find(u) != find(v)) {
            combine(u, v);
            --conn;
            addEdge(u, v, d[u][v]);
        }
    }
    dfs(1, 0, 0, 0);
    for (int i = 1; i <= n && valid; ++i) {
        for (int j = i; j <= n && valid; ++j) {
            if (calcDist(i, j) != d[i][j]) {
                valid = false;
            }
        }
    }
    puts(valid ? "YES" : "NO");
    return 0;
}
