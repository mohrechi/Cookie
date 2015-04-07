#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXK = 18;

int n, m;

struct Edge {
    int v, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum;

void initGraph() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(const int &u, const int &v) {
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(const int &u, const int &v) {
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

int father[MAXN][MAXK];
int depth[MAXN], nodeNum[MAXN];

int initFather(int u, int f, int d) {
    father[u][0] = f;
    for (int k = 1; k < MAXK && father[u][k - 1] != -1; ++k) {
        father[u][k] = father[father[u][k - 1]][k - 1];
    }
    depth[u] = d;
    nodeNum[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != f) {
            nodeNum[u] += initFather(v, u, d + 1);
        }
    }
    return nodeNum[u];
}

int lca(int a, int b) {
    int k = MAXK - 1;
    while (depth[a] != depth[b]) {
        if (depth[a] > depth[b]) {
            while (father[a][k] == -1 || depth[father[a][k]] < depth[b]) {
                --k;
            }
            a = father[a][k];
        } else {
            swap(a, b);
        }
    }
    if (a == b) {
        return a;
    }
    k = MAXK - 1;
    while (a != b) {
        while (father[a][k] == father[b][k] && k > 0) {
            --k;
        }
        a = father[a][k];
        b = father[b][k];
    }
    return a;
}

int find(int a, int decDepth) {
    int k = MAXK - 1;
    int finalDepth = depth[a] - decDepth;
    while (depth[a] != finalDepth) {
        while (father[a][k] == -1 || depth[father[a][k]] < finalDepth) {
            --k;
        }
        a = father[a][k];
    }
    return a;
}

int main() {
    int u, v;
    while (cin >> n) {
        initGraph();
        for (int i = 1; i < n; ++i) {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        memset(father, -1, sizeof(father));
        initFather(1, -1, 0);
        cin >> m;
        while (m--) {
            scanf("%d%d", &u, &v);
            if (u == v) {
                printf("%d\n", n);
            } else {
                int g = lca(u, v);
                int dist = depth[u] + depth[v] - 2 * depth[g];
                if (dist & 1) {
                    puts("0");
                } else {
                    int ans;
                    if (depth[u] == depth[v]) {
                        ans = n - nodeNum[find(u, dist / 2 - 1)] - nodeNum[find(v, dist / 2 - 1)];
                    } else {
                        if (depth[u] < depth[v]) {
                            swap(u, v);
                        }
                        ans = nodeNum[find(u, dist / 2)] - nodeNum[find(u, dist / 2 - 1)];
                    }
                    printf("%d\n", ans);
                }
            }
        }
    }
    return 0;
}
