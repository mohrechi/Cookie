#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;

int n, leafNum;
struct Edge {
    int v, next;
} edge[MAXN];
int head[MAXN], edgeNum;

int dp[MAXN];

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v) {
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

int dfs(int u, int s) {
    if (head[u] == -1) {
        ++leafNum;
        return 1;
    }
    if (s == 0) {
        dp[u] = 0x7fffffff;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            dp[u] = min(dp[u], dfs(edge[i].v, 1));
        }
    } else {
        dp[u] = 0;
        for (int i = head[u]; i != -1; i = edge[i].next) {
            dp[u] += dfs(edge[i].v, 0);
        }
    }
    return dp[u];
}

int main() {
    ios::sync_with_stdio(false);
    int u, v;
    while (cin >> n) {
        clearEdge();
        for (int i = 1; i < n; ++i) {
            cin >> u >> v;
            addEdge(u, v);
        }
        leafNum = 0;
        u = dfs(1, 0);
        v = dfs(1, 1);
        cout << (leafNum >> 1) - u + 1 << " " << v << endl;
    }
    return 0;
}
