#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50000 + 10;
const int MAXK = 500 + 10;

int n, k;
int dp[MAXN][MAXK];

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

long long ans;

void dfs(int u, int f) {
    dp[u][0] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        if (v != f) {
            dfs(v, u);
            for (int j = 1; j < k; ++j) {
                ans += (long long)dp[v][j - 1] * dp[u][k - j];
            }
            for (int j = 1; j <= k; ++j) {
                dp[u][j] += dp[v][j - 1];
            }
        }
    }
    ans += dp[u][k];
}

int main() {
    int u, v;
    scanf("%d%d", &n, &k);
    clearEdge();
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}
