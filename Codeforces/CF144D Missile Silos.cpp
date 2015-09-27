#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n, m, s, l;
struct Edge {
    int u, v, w, next;
} edge[MAXN * 2];
int head[MAXN], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w) {
    edge[edgeNum] = {u, v, w, head[u]};
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int w) {
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, w);
}

int dist[MAXN];
bool visit[MAXN];

void spfa() {
    queue<int> q;
    q.push(s);
    memset(dist, 0x3f, sizeof(dist));
    memset(visit, false, sizeof(visit));
    dist[s] = 0;
    visit[s] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int& v = edge[i].v;
            int& w = edge[i].w;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!visit[v]) {
                    visit[v] = true;
                    q.push(v);
                }
            }
        }
        visit[u] = false;
    }
}

int main() {
    int u, v, w;
    scanf("%d%d%d", &n, &m, &s);
    clearEdge();
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    scanf("%d", &l);
    spfa();
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        cnt += dist[i] == l;
    }
    for (int i = 0; i < m; ++i) {
        int j = i * 2;
        int& u = edge[j].u;
        int& v = edge[j].v;
        int& w = edge[j].w;
        if (l > dist[u] && l > dist[v] && l - dist[u] + l - dist[v] == w) {
            ++cnt;
        } else {
            if (l > dist[u] && l < dist[u] + w && w - (l - dist[u]) + dist[v] > l) {
                ++cnt;
            }
            if (l > dist[v] && l < dist[v] + w && w - (l - dist[v]) + dist[u] > l) {
                ++cnt;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
