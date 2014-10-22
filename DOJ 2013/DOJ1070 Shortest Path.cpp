#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int MAXM = 100005;
const int MOD = 1000000000;

int n, m;
struct Edge {
    int v, w, next;
} edge[MAXM * 2];
int head[MAXN], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w) {
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

int queue[MAXN];
bool visit[MAXN];
long long dist[MAXN];

void spfa() {
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    queue[0] = 1;
    visit[1] = true;
    dist[1] = 0;
    while (front != rear) {
        int u = queue[front];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            int w = edge[i].w;
            if (dist[v] == -1 || dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if (!visit[v]) {
                    visit[v] = true;
                    queue[rear] = v;
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
    int T;
    int u, v, w;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        clearEdge();
        for (int i = 0; i < m; ++i) {
            scanf("%d%d%d", &u, &v, &w);
            w += MOD;
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        spfa();
        printf("%lld\n", dist[n] % MOD);
    }
    return 0;
}
