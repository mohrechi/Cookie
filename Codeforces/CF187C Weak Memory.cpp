#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = 4e5 + 10;

int n, m, k;
bool guide[MAXN];
struct Edge {
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNum;
int s, t;

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

int que[MAXN];
int dist[MAXN];
bool visit[MAXN];

bool spfa(int limit) {
    int front = 0, rear = 1;
    memset(dist, -1, sizeof(dist));
    memset(visit, false, sizeof(visit));
    que[0] = s;
    visit[s] = true;
    dist[s] = 0;
    while (front != rear) {
        int u = que[front];
        if (++front >= MAXN) {
            front = 0;
        }
        if (dist[u] == limit) {
            visit[u] = false;
            continue;
        }
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            if (dist[v] == -1 || dist[v] > dist[u] + 1) {
                if (v == t) {
                    return true;
                }
                dist[v] = dist[u] + 1;
                if (guide[v]) {
                    dist[v] = 0;
                }
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
    }
    return false;
}

int main() {
    int g, u, v;
    scanf("%d%d%d", &n, &m, &k);
    while (k--) {
        scanf("%d", &g);
        guide[g] = true;
    }
    clearEdge();
    while (m--) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    scanf("%d%d", &s, &t);
    int l = 1, r = n, ans = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (spfa(mid)) {
            r = mid - 1;
            if (ans == -1 || ans > mid) {
                ans = mid;
            }
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
