#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = MAXN * 2;

int n, m;
struct Edge {
    int u, v, z, next;
    bool operator <(const Edge& edge) const {
        if (u == edge.u) {
            return v < edge.v;
        }
        return u < edge.u;
    }
} edge[MAXM];
int head[MAXN], edgeNum;

set<Edge> path;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int z) {
    edge[edgeNum] = {u, v, z, head[u]};
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int z) {
    addEdgeSub(u, v, z);
    addEdgeSub(v, u, z);
}

bool visit[MAXN];
int pre[MAXN], que[MAXN], dis[MAXN], cost[MAXN];

void spfa() {
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dis, 0x3f, sizeof(dis));
    memset(pre, -1, sizeof(pre));
    memset(cost, 0, sizeof(cost));
    visit[1] = false;
    dis[1] = 0;
    que[0] = 1;
    while (front != rear) {
        int u = que[front];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            int z = edge[i].z;
            if (dis[v] > dis[u] + 1 || (dis[v] == dis[u] + 1 && cost[v] < cost[u] + z)) {
                dis[v] = dis[u] + 1;
                cost[v] = cost[u] + z;
                pre[v] = i;
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
    int u, v, z;
    ios::sync_with_stdio(false);
    while (cin >> n >> m) {
        clearEdge();
        for (int i = 0; i < m; ++i) {
            cin >> u >> v >> z;
            addEdge(u, v, z);
        }
        spfa();
        path.clear();
        int t = n;
        while (t != 1) {
            path.insert(edge[pre[t]]);
            path.insert(edge[pre[t] ^ 1]);
            t = edge[pre[t]].u;
        }
        int cnt = 0;
        for (int i = 0; i < m * 2; i += 2) {
            if ((path.find(edge[i]) != path.end()) ^ edge[i].z) {
                ++cnt;
            }
        }
        cout << cnt << endl;
        for (int i = 0; i < m * 2; i += 2) {
            if ((path.find(edge[i]) != path.end()) ^ edge[i].z) {
                cout << edge[i].u << ' ' << edge[i].v << ' ' << (not edge[i].z) << endl;
            }
        }
    }
    return 0;
}
