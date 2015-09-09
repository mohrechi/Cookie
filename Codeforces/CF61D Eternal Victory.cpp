#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n;
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

long long dfs(int u, int f) {
    long long ret = 0;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int& v = edge[i].v;
        if (v == f) {
            continue;
        }
        int& w = edge[i].w;
        ret = max(ret, dfs(v, u) + edge[i].w);
    }
    return ret;
}

int main() {
    int u, v, w;
    scanf("%d", &n);
    clearEdge();
    long long total = 0;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
        total += w * 2;
    }
    cout << total - dfs(1, 0) << endl;
    return 0;
}
