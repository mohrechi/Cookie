#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MAXM = MAXN * 2 + 10;

int n;
struct Edge {
    int i, v, next;
    bool used;
} edge[MAXM * 2];
int head[MAXM], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int i, int u, int v) {
    edge[edgeNum] = {i, v, head[u], false};
    head[u] = edgeNum++;
}

inline void addEdge(int i, int u, int v) {
    addEdgeSub(i, u, v);
    addEdgeSub(i, v, u);
}

bool visit[MAXM];
int degree[MAXM], odds[MAXM];
int stk[MAXM], top;

void dfs(int u) {
    visit[u] = true;
    for (int i = head[u]; i != -1; i = head[u]) {
        head[u] = edge[i].next;
        if (edge[i].used) {
            continue;
        }
        edge[i^1].used = true;
        dfs(edge[i].v);
        stk[top++] = edge[i].i;
    }
}

char ans[MAXN];

void clearStack() {
    bool flag = false;
    for (int i = top - 1; i >= 0; --i) {
        flag = not flag;
        ans[stk[i]] = flag ? 'r' : 'b';
    }
    top = 0;
}

int main() {
    int x, y;
    scanf("%d", &n);
    clearEdge();
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x, &y);
        y += MAXN;
        addEdge(i, x, y);
        ++degree[x];
        ++degree[y];
    }
    int oddNum = 0;
    for (int i = 0; i < MAXM; ++i) {
        if (degree[i] & 1) {
            odds[oddNum++] = i;
        }
    }
    for (int i = 0; i < oddNum; i += 2) {
        addEdge(MAXN - 1, odds[i], odds[i + 1]);
    }
    for (int i = 0; i < oddNum; ++i) {
        if (not visit[odds[i]]) {
            dfs(odds[i]);
            clearStack();
        }
    }
    for (int i = 0; i < MAXM; ++i) {
        if (degree[i] and not visit[i]) {
            dfs(i);
            clearStack();
        }
    }
    puts(ans);
    return 0;
}
