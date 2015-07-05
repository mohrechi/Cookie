#include <cstdio>
#include <cstring>
const int MAXN = 100 + 10;
const int MAXM = MAXN * MAXN;

int n, m;
struct Edge {
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNum;

inline void clearGraph() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v) {
    edge[edgeNum] = {v, head[u]};
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v) {
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

int ans;

int dfs(int u, int p) {
    int num = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != p) {
            num += dfs(v, u);
        }
    }
    if (num % 2 == 0) {
        num = 0;
        ++ans;
    }
    return num;
}

int main() {
    int u, v;
    while (~scanf("%d%d", &n, &m)) {
        clearGraph();
        while (m--) {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        ans = -1;
        dfs(u, 0);
        printf("%d\n", ans);
    }
    return 0;
}
