#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3000 + 10;
const int MAXM = MAXN * 2;

int n, m;
struct Edge {
    int v, next;
} edge[MAXM];
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

int dist[MAXN][MAXN];

bool visit[MAXN];
int que[MAXN];

void spfa(int start) {
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist[start], 0x11, sizeof(dist[start]));
    visit[start] = true;
    dist[start][start] = 0;
    que[0] = start;
    while (front != rear) {
        int u = que[front];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (dist[start][v] > dist[start][u] + 1) {
                dist[start][v] = dist[start][u] + 1;
                if (not visit[v]) {
                    visit[v] = true;
                    que[rear] = v;
                    if (++rear >= MAXN) {
                        rear = 0;
                    }
                }
            }
        }
        visit[u] = false;
        if (++front >= MAXN) {
            front = 0;
        }
    }
}

int main() {
    int u, v;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    clearEdge();
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        addEdge(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        spfa(i);
    }
    int s1, t1, l1;
    int s2, t2, l2;
    cin >> s1 >> t1 >> l1;
    cin >> s2 >> t2 >> l2;
    if (dist[s1][t1] > l1 or dist[s2][t2] > l2) {
        cout << -1 << endl;
    } else {
        int ans = dist[s1][t1] + dist[s2][t2];
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (dist[s1][i] + dist[i][j] + dist[j][t1] <= l1 and dist[s2][i] + dist[i][j] + dist[j][t2] <= l2) {
                    ans = min(ans, dist[s1][i] + dist[s2][i] + dist[i][j] + dist[j][t2] + dist[j][t1]);
                }
                if (dist[s1][i] + dist[i][j] + dist[j][t1] <= l1 and dist[t2][i] + dist[i][j] + dist[j][s2] <= l2) {
                    ans = min(ans, dist[s1][i] + dist[t2][i] + dist[i][j] + dist[j][s2] + dist[j][t1]);
                }
            }
        }
        cout << m - ans << endl;
    }
    return 0;
}
