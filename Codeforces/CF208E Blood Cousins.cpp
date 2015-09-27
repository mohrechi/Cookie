#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n;
struct Edge {
    int v, next;
} edge[MAXN];
int head[MAXN], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v) {
    edge[edgeNum] = {v, head[u]};
    head[u] = edgeNum++;
}

int globalId, id[MAXN], far[MAXN], depth[MAXN];
vector<int> layer[MAXN];
int parent[MAXN][20];

void dfs(int u, int d) {
    id[u] = far[u] = globalId++;
    depth[u] = d;
    layer[d].push_back(id[u]);
    for (int i = 1; parent[u][i - 1] != 0; ++i) {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        dfs(v, d + 1);
        far[u] = max(far[u], far[v]);
    }
}

int getParent(int u, int k) {
    for (int i = 0; (1 << i) <= k; ++i) {
        if (k & (1 << i)) {
            u = parent[u][i];
        }
    }
    return u;
}

int main() {
    scanf("%d", &n);
    clearEdge();
    for (int i = 1, r; i <= n; ++i) {
        scanf("%d", &r);
        addEdge(r, i);
        parent[i][0] = r;
    }
    dfs(0, 0);
    int m, v, p;
    scanf("%d", &m);
    while (m--) {
        scanf("%d%d", &v, &p);
        if (depth[v] - p <= 0) {
            puts("0");
            continue;
        }
        int u = getParent(v, p);
        p = depth[v];
        int layerL = layer[p].size();
        int layerR = -1;
        int l = 0, r = (int)layer[p].size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (layer[p][mid] >= id[u]) {
                r = mid - 1;
                layerL = min(layerL, mid);
            } else {
                l = mid + 1;
            }
        }
        l = 0, r = (int)layer[p].size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (layer[p][mid] <= far[u]) {
                l = mid + 1;
                layerR = max(layerR, mid);
            } else {
                r = mid - 1;
            }
        }
        printf("%d\n", max(0, layerR - layerL));
    }
    return 0;
}
