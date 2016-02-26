#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 5;
const int MAXM = 100000 * 2 + 5;

int n, m;
struct Edge {
    int v, w, next;
} edge[MAXM];
int head[MAXN], edgeNum;

void initEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w) {
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int w) {
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, w);
}

int dist[MAXN][2];
int queue[MAXN];
bool visit[MAXN];

inline void tryAdd(int& rear, int v) {
    if (!visit[v]) {
        visit[v] = true;
        queue[rear] = v;
        if (++rear >= MAXN) {
            rear = 0;
        }
    }
}

void spfa() {
    int front = 0, rear = 1;
    memset(dist, 0x3f, sizeof(dist));
    memset(visit, false, sizeof(visit));
    dist[1][0] = 0;
    visit[1] = true;
    queue[0] = 1;
    while (front != rear) {
        int u = queue[front];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            int w = edge[i].w;
            if (dist[u][0] + w < dist[v][0]) {
                dist[v][1] = dist[v][0];
                dist[v][0] = dist[u][0] + w;
                tryAdd(rear, v);
            }
            if (dist[u][0] + w > dist[v][0] && dist[u][0] + w < dist[v][1]) {
                dist[v][1] = dist[u][0] + w;
                tryAdd(rear, v);
            }
            if (dist[u][1] + w > dist[v][0] && dist[u][1] + w < dist[v][1]) {
                dist[v][1] = dist[u][1] + w;
                tryAdd(rear, v);
            }
        }
        visit[u] = false;
        if (++front >= MAXN) {
            front = 0;
        }
    }
}

int main() {
    int u, v, w;
    while (scanf("%d%d", &n, &m) != EOF) {
        initEdge();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
        }
        spfa();
        printf("%d\n", dist[n][1]);
    }
    return 0;
}
