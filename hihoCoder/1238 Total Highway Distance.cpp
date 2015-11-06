#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 5;

int n, m;
struct Edge {
    int v, w, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum;
int parent[MAXN];

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w) {
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int w) {
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, w);
}

int num[MAXN], weight[MAXN];

long long getDist(int u, int p, int w) {
    long long d = 0;
    parent[u] = p;
    weight[u] = w;
    num[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != p) {
            d += getDist(v, u, edge[i].w);
            num[u] += num[v];
        }
    }
    if (u != 1) {
        d += (long long)num[u] * (n - num[u]) * w;
    }
    return d;
}

long long total;
char op[20];

int main() {
    int u, v, w;
    scanf("%d%d", &n, &m);
    clearEdge();
    for (int i = 1; i < n; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    total = getDist(1, 0, 0);
    while (m--) {
        scanf("%s", op);
        if (op[0] == 'Q') {
            cout << total << endl;
        } else {
            scanf("%d%d%d", &u, &v, &w);
            if (parent[u] != v) {
                swap(u, v);
            }
            total += (long long)num[u] * (n - num[u]) * (w - weight[u]);
            weight[u] = w;
        }
    }
    return 0;
}
