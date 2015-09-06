#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
const int MAXM = MAXN * 2;

int n, r1, r2;
struct Edge {
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNum;

void clearEdge() {
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

int np[MAXN];

void dfs(int u, int p) {
    np[u] = p;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int& v = edge[i].v;
        if (v != p) {
            dfs(v, u);
        }
    }
}

int main() {
    int p;
    scanf("%d%d%d", &n, &r1, &r2);
    clearEdge();
    for (int i = 1; i <= n; ++i) {
        if (i == r1) {
            continue;
        }
        scanf("%d", &p);
        addEdge(p, i);
    }
    dfs(r2, 0);
    for (int i = 1; i <= n; ++i) {
        if (i == r2) {
            continue;
        }
        printf("%d ", np[i]);
    }
    putchar('\n');
    return 0;
}
