#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;

int n, m, s, t;
struct Edge {
    int v, next;
    double p;
} edge[MAXN * 2];
int head[MAXN], edgeNum;

inline void initGraph() {
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, double p) {
    edge[edgeNum].v = v;
    edge[edgeNum].p = p;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, double p) {
    addEdgeSub(u, v, p);
    addEdgeSub(v, u, p);
}

struct Dist {
    double p;
    int num;

    Dist() {
        p = -0.1;
        num = MAXN;
    }

    bool operator <(const Dist& dist) const {
        if (num == dist.num) {
            return p > dist.p;
        }
        return num < dist.num;
    }
};

int q[MAXN], prevv[MAXN], stk[MAXN];
bool visit[MAXN];
Dist dists[MAXN];

int main() {
    int u, v, p;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    initGraph();
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &p);
        addEdge(u, v, 1.0 - p * 0.01);
    }
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    q[0] = s;
    prevv[s] = -1;
    visit[s] = true;
    dists[s].num = 1;
    dists[s].p = 1.0;
    while (front < rear) {
        int u = q[front];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            double p = edge[i].p;
            Dist dist;
            dist.num = dists[u].num + 1;
            dist.p = dists[u].p * p;
            if (dist < dists[v]) {
                dists[v] = dist;
                prevv[v] = u;
                if (!visit[v]) {
                    visit[v] = true;
                    q[rear] = v;
                    if (++rear >= MAXN) {
                        rear = 0;
                    }
                }
            }
        }
        visit[u] = true;
        if (++front >= MAXN) {
            front = 0;
        }
    }
    printf("%d %.8f\n", dists[t].num, 1.0 - dists[t].p);
    int top = 0;
    u = t;
    while (u != -1) {
        stk[top++] = u;
        u = prevv[u];
    }
    for (int i = top - 1; i >= 0; --i) {
        if (i < top - 1) {
            putchar(' ');
        }
        printf("%d", stk[i]);
    }
    putchar('\n');
    return 0;
}
