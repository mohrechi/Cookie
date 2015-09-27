#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;

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

int que[MAXN], dist[MAXN];

int bfs(int u, int &far) {
    int front = 0, rear = 1;
    memset(dist, 0x3f, sizeof(dist));
    dist[u] = 0;
    que[0] = u;
    far = u;
    while (front < rear) {
        u = que[front++];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int& v = edge[i].v;
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                que[rear++] = v;
                if (dist[v] > dist[far]) {
                    far = v;
                }
            }
        }
    }
    return dist[far];
}

int main() {
    int n, m, u, v;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int len = 0;
    while (n--) {
        scanf("%d", &m);
        clearEdge();
        for (int i = 1; i < m; ++i) {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        bfs(1, v);
        len += bfs(v, u);
    }
    printf("%d\n", len);
    return 0;
}
