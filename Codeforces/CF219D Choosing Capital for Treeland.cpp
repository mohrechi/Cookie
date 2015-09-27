#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;

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

inline void addEdge(int u, int v) {
    addEdgeSub(u, v, -1);
    addEdgeSub(v, u, 1);
}

int downNum[MAXN], upNum[MAXN];

void countNum(int u, int f) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int& v = edge[i].v;
        if (v != f) {
            int& w = edge[i].w;
            if (w == -1) {
                ++downNum[u];
            } else {
                ++upNum[u];
            }
            countNum(v, u);
            downNum[u] += downNum[v];
            upNum[u] += upNum[v];
        }
    }
}

int dist[MAXN];

void calcDist(int u, int f, int cul) {
    dist[u] = cul + upNum[u];
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int& v = edge[i].v;
        if (v != f) {
            int& w = edge[i].w;
            calcDist(v, u, cul + (upNum[u] - upNum[v]) - w);
        }
    }
}

int main() {
    int u, v;
    scanf("%d", &n);
    clearEdge();
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    countNum(1, 0);
    calcDist(1, 0, 0);
    int minVal = n;
    for (int i = 1; i <= n; ++i) {
        minVal = min(minVal, dist[i]);
    }
    printf("%d\n", minVal);
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == minVal) {
            printf("%d ", i);
        }
    }
    putchar('\n');
    return 0;
}
