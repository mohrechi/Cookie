#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000 + 5;
const int MOD = 1e9 + 7;

int d, n;
struct Node {
    int idx, a;
    bool operator <(const Node &node) const {
        return a > node.a;
    }
} node[MAXN];
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

bool valid[MAXN];

long long dfs(int u, int p = 0) {
    long long num = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int& v = edge[i].v;
        if (v != p && valid[v]) {
            (num *= dfs(v, u)) %= MOD;
        }
    }
    num += p != 0;
    return num;
}

int main() {
    int u, v;
    scanf("%d%d", &d, &n);
    for (int i = 1; i <= n; ++i) {
        node[i].idx = i;
        scanf("%d", &node[i].a);
    }
    sort(node + 1, node + 1 + n);
    clearEdge();
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(valid, false, sizeof(valid));
        for (int j = i; j <= n; ++j) {
            if (node[i].a - node[j].a <= d) {
                valid[node[j].idx] = true;
            } else {
                break;
            }
        }
        ans += dfs(node[i].idx);
    }
    cout << ans % MOD << endl;
    return 0;
}
