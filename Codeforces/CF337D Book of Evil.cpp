#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXE = MAXN * 2 + 5;

int n, m, d;
struct Edge {
    int v, next;
} edge[MAXE];
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

bool infected[MAXN];
int dist1[MAXN], dist2[MAXN];

void dfs1(int u, int p) {
    if (infected[u]) {
        dist1[u] = 0;
    } else {
        dist1[u] = -1;
    }
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int& v = edge[i].v;
        if (v == p) {
            continue;
        }
        dfs1(v, u);
        if (dist1[v] != -1) {
            dist1[u] = max(dist1[u], dist1[v] + 1);
        }
    }
}

void dfs2(int u, int p, int d) {
    dist2[u] = max(dist1[u], d);
    int maxD = -1, secD = -1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int& v = edge[i].v;
        if (v == p) {
            continue;
        }
        if (dist1[v] != -1) {
            if (dist1[v] >= maxD) {
                secD = maxD;
                maxD = dist1[v];
            } else if (dist1[v] > secD) {
                secD = dist1[v];
            }
        }
    }
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int& v = edge[i].v;
        if (v == p) {
            continue;
        }
        int next = d == -1 ? -1 : d + 1;
        if (infected[u]) {
            next = max(next, 1);
        }
        if (dist1[v] == maxD) {
            if (secD != -1) {
                next = max(next, secD + 2);
            }
        } else {
            if (maxD != -1) {
                next = max(next, maxD + 2);
            }
        }
        dfs2(v, u, next);
    }
}

int main() {
    int p, a, b;
    scanf("%d%d%d", &n, &m, &d);
    while (m--) {
        scanf("%d", &p);
        infected[p] = true;
    }
    clearEdge();
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &a, &b);
        addEdge(a, b);
    }
    dfs1(1, 0);
    dfs2(1, 0, -1);
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist2[i] <= d) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
