#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10000 + 10;
const int MAXM = 100000 + 10;

const int UP = 0;
const int DOWN = 1;

int n, m, s, t;
struct Edge {
    int v, next;
    int type;
} edge[MAXM * 2];
int head[MAXN], edgeNum;

void initGraph() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

void addEdgeSub(int u, int v, int type) {
    edge[edgeNum].v = v;
    edge[edgeNum].type = type;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

void addEdge(int u, int v) {
    addEdgeSub(u, v, UP);
    addEdgeSub(v, u, DOWN);
}

int qu[MAXN], qt[MAXN], dist[MAXN][2];
bool visit[MAXN][2];

int spfa() {
    int front = 0, rear = 2;
    memset(dist, 0x3f, sizeof(dist));
    qu[0] = s;
    qt[0] = UP;
    qu[1] = s;
    qt[1] = DOWN;
    dist[s][UP] = dist[s][DOWN] = 0;
    visit[s][UP] = visit[s][DOWN] = true;
    while (front != rear) {
        int u = qu[front];
        int ut = qt[front];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            int type = edge[i].type;
            if (dist[v][type] > dist[u][ut] + (type != ut)) {
                dist[v][type] = dist[u][ut] + (type != ut);
                if (!visit[v][type]) {
                    visit[v][type] = true;
                    qu[rear] = v;
                    qt[rear] = type;
                    if (++rear >= MAXN) {
                        rear = 0;
                    }
                }
            }
        }
        visit[u][ut] = false;
        if (++front >= MAXN) {
            front = 0;
        }
    }
    return min(dist[t][UP], dist[t][DOWN]);;
}

int main() {
    int u, v;
    scanf("%d%d", &n, &m);
    initGraph();
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    scanf("%d%d", &s, &t);
    printf("%d\n", spfa());
    return 0;
}
