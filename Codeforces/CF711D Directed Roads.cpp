#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MOD = 1e9 + 7;

int n, mod2[MAXN];

void init() {
    mod2[0] = 1;
    for (int i = 1; i <= n; ++i) {
        mod2[i] = (mod2[i - 1] << 1) % MOD;
    }
}

struct Edge {
    int v, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum = 2;

inline void addEdgeSub(int u, int v) {
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v) {
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

bool hasLoop;
int visited[MAXN], depth[MAXN], blockSize, loopSize;

void dfs(int u, int p = 0, int d = 1) {
    blockSize += 1;
    visited[u] = true;
    depth[u] = d;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (p == (i ^ 1)) {
            continue;
        }
        if (visited[v]) {
            if (!hasLoop) {
                hasLoop = true;
                loopSize = d - depth[v] + 1;
            }
            continue;
        }
        dfs(v, i, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    init();
    for (int u = 1, v; u <= n; ++u) {
        cin >> v;
        addEdge(u, v);
    }
    long long ans = 1;
    for (int u = 1; u <= n; ++u) {
        if (!visited[u]) {
            hasLoop = false;
            blockSize = 0;
            dfs(u);
            long long base = 1, rest = mod2[blockSize];
            if (hasLoop) {
                base = (mod2[loopSize] - 2 + MOD) % MOD;
                rest = mod2[blockSize - loopSize];
            }
            (ans *= (base * rest) % MOD) %= MOD;
        }
    }
    cout << ans << endl;
    return 0;
}
