#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 10;

int n;
struct Edge {
    int v, next;
} edge[MAXN * 2];
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

int dist[MAXN];
queue<int> que;

int stk[MAXN], top, timeStamp;
bool inStack[MAXN];
int dfn[MAXN], low[MAXN];
int group[MAXN], groupNum;

void tarjan(int u, int p) {
    dfn[u] = low[u] = timeStamp++;
    inStack[u] = true;
    stk[top++] = u;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v == p) {
            continue;
        }
        if (dfn[v] == -1) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else if (inStack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        groupNum = 0;
        int t;
        do {
            t = stk[--top];
            group[groupNum++] = t;
            inStack[t] = false;
        } while (t != u);
        if (groupNum > 1) {
            for (int i = 0; i < groupNum; ++i) {
                dist[group[i]] = 0;
                que.push(group[i]);
            }
        }
    }
}

void solve() {
    memset(dist, -1, sizeof(dist));
    memset(inStack, false, sizeof(inStack));
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    top = timeStamp = 0;
    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == -1) {
            tarjan(i, 0);
        }
    }
}

int main() {
    int u, v;
    scanf("%d", &n);
    clearEdge();
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    solve();
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", dist[i]);
    }
    putchar('\n');
    return 0;
}
