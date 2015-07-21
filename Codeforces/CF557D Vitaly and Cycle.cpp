#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = MAXN * 2;

int n, m;
struct Edge {
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNum = 2;
long long ans;

inline void addEdgeSub(int u, int v) {
    edge[edgeNum] = {v, head[u]};
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v) {
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

int degree[MAXN];
bool visit[MAXN], color[MAXN];
int blackNum, whiteNum;

bool dfs(int u, int f, bool c) {
    visit[u] = true;
    color[u] = c;
    c ? ++whiteNum : ++blackNum;
    for (int i = head[u]; i; i = edge[i].next) {
        int v = edge[i].v;
        if (v == f) {
            continue;
        }
        if (visit[v]) {
            if ((c - color[v]) % 2 == 0) {
                return true;
            }
        } else {
            if (dfs(v, u, not c)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int u, v;
    scanf("%d%d", &n, &m);
    int maxDegree = 0;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        maxDegree = max(maxDegree, ++degree[u]);
        maxDegree = max(maxDegree, ++degree[v]);
    }
    if (m == 0) {
        cout << 3 << " " << 1LL * n * (n - 1) * (n - 2) / 6 << endl;
    } else if (maxDegree == 1) {
        cout << 2 << " " << 1LL * m * (n - 2) << endl;
    } else {
        bool hasOdd = false;
        for (int i = 1; i <= n; ++i) {
            if (not visit[i]) {
                blackNum = whiteNum = 0;
                if (dfs(i, 0, 0)) {
                    hasOdd = true;
                    break;
                } else if (blackNum > 0 and whiteNum > 0) {
                    ans += 1LL * blackNum * (blackNum - 1) / 2;
                    ans += 1LL * whiteNum * (whiteNum - 1) / 2;
                }
            }
        }
        if (hasOdd) {
            cout << 0 << " " << 1 << endl;
        } else {
            cout << 1 << " " << ans << endl;
        }
    }
    return 0;
}
