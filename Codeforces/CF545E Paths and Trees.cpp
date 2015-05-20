#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
const int MAXM = MAXN * 2;

int n, m;
struct Edge {
    int v, w, next;
} edge[MAXM];
int head[MAXN], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w) {
    edge[edgeNum] = {v, w, head[u]};
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int w) {
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, w);
}

struct Dist {
    int path, prev;
    long long weight;
    bool operator <(const Dist& dist) const {
        if (weight == dist.weight) {
            return path < dist.path;
        }
        return weight < dist.weight;
    }
} dist[MAXN];

int que[MAXN];
bool visit[MAXN];

void spfa(int u) {
    int front = 0, rear = 1;
    for (int i = 1; i <= n; ++i) {
        dist[i].path = MAXN;
        dist[i].weight = 0x3f3f3f3f3f3f3f3fLL;
        dist[i].prev = -1;
        visit[i] = false;
    }
    dist[u].path = 0;
    dist[u].weight = 0;
    visit[u] = true;
    que[0] = u;
    while (front != rear) {
        u = que[front];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            int v = edge[i].v;
            int w = edge[i].w;
            Dist vd = {w, i, dist[u].weight + w};
            if (vd < dist[v]) {
                dist[v] = vd;
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
    int u, v, w;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    clearEdge();
    for (int i = 1; i <= m; ++i) {
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    cin >> u;
    spfa(u);
    long long sum = 0;
    vector<int> edges;
    for (int i = 1; i <= n; ++i) {
        if (dist[i].prev != -1) {
            sum += edge[dist[i].prev].w;
            edges.push_back((dist[i].prev >> 1) + 1);
        }
    }
    sort(edges.begin(), edges.end());
    cout << sum << endl;
    for (auto e : edges) {
        cout << e << ' ';
    }
    cout << endl;
    return 0;
}
