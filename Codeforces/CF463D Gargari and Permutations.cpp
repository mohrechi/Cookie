#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 + 10;
const int MAXK = 5;

int n, k;
int a[MAXK][MAXN];
int pos[MAXK][MAXN];

struct Edge {
    int v, next;
} edge[MAXN * MAXN / 2];
int head[MAXN], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v) {
    edge[edgeNum] = {v, head[u]};
    head[u] = edgeNum++;
}

int degree[MAXN], dist[MAXN];
bool visit[MAXN];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i) {
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &a[i][j]);
            pos[i][a[i][j]] = j;
        }
    }
    clearEdge();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            bool flag = true;
            for (int l = 0; l < k; ++l) {
                if (pos[l][i] >= pos[l][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                addEdge(i, j);
                ++degree[j];
            }
        }
    }
    queue<int> que;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] == 0) {
            que.push(i);
            visit[i] = true;
            dist[i] = 1;
        }
    }
    int ans = 1;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (dist[v] < dist[u] + 1) {
                dist[v] = dist[u] + 1;
                ans = max(ans, dist[v]);
                if (!visit[v]) {
                    visit[v] = true;
                    que.push(v);
                }
            }
        }
        visit[u] = false;
    }
    printf("%d\n", ans);
    return 0;
}
