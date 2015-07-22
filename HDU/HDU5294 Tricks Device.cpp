#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 2000 + 10;
const int MAXM = 60000 + 10;

int n, m;
struct Edge {
    int u, v, w, f, next;
} edge[MAXM * 2];
int head[MAXN], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w) {
    edge[edgeNum].u = u;
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].f = 0;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int w) {
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, w);
}

struct Dist {
    int w, d;
    Dist operator +(int vw) {
        Dist dist;
        dist.w = w + vw;
        dist.d = d + 1;
        return dist;
    }
    bool operator <(const Dist &dist) const {
        if (w == dist.w) {
            return d < dist.d;
        }
        return w < dist.w;
    }
} dist[MAXN];

int que[MAXN];
bool visit[MAXN];

void spfa() {
    int front = 0, rear = 1;
    memset(dist, 0x3f, sizeof(dist));
    memset(visit, false, sizeof(visit));
    dist[1].w = 0;
    dist[1].d = 0;
    que[front] = 1;
    visit[front] = true;
    while (front != rear) {
        int u = que[front];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            int w = edge[i].w;
            Dist dv = dist[u] + w;
            if (dv < dist[v]) {
                dist[v] = dv;
                if (!visit[v]) {
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

void addFlow() {
    for (int u = 1; u <= n; ++u) {
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (dist[v].w - dist[u].w == edge[i].w) {
                edge[i].f = 1;
            }
        }
    }
}

int mark[MAXN];

bool bfs() {
    int front = 0, rear = 1;
    memset(mark, -1, sizeof(mark));
    que[0] = 1;
    mark[1] = 0;
    while (front < rear) {
        int u = que[front++];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (edge[i].f && mark[v] == -1) {
                mark[v] = mark[u] + 1;
                que[rear++] = v;
                if (v == n) {
                    return true;
                }
            }
        }
    }
    return false;
}

int dfs(int u, int flow) {
    if (u == n) {
        return flow;
    }
    int ret = 0;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        int f = 0;
        if (mark[v] == mark[u] + 1 && edge[i].f && (f = dfs(v, min(flow - ret, edge[i].f)))) {
            edge[i].f -= f;
            edge[i ^ 1].f += f;
            ret += f;
            if (ret == flow) {
                return ret;
            }
        }
    }
    if (ret == 0) {
        mark[u] = -1;
    }
    return ret;
}

int dinic() {
    int ans = 0;
    while (bfs()) {
        int temp = 0;
        while (temp = dfs(1, 0x3f3f3f3f)) {
            ans += temp;
        }
    }
    return ans;
}

int main() {
    int u, v, w;
    while (scanf("%d%d", &n, &m) != EOF) {
        clearEdge();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        spfa();
        int ans2 = m - dist[n].d;
        addFlow();
        int ans1 = dinic();
        printf("%d %d\n", ans1, ans2);
    }
    return 0;
}
