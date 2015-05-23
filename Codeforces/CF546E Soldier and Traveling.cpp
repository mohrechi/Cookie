#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = 200 + 10;
const int MAXH = MAXN * 2 + 2;
const int MAXE = (MAXN * 3 + MAXM * 2) * 2;

int n, m;
int a[MAXN], b[MAXN];
struct Edge {
    int v, f, next;
} edge[MAXE];
int head[MAXH], edgeNum;

void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int f) {
    edge[edgeNum] = {v, f, head[u]};
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int f) {
    addEdgeSub(u, v, f);
    addEdgeSub(v, u, 0);
}

int src, dst = 2 * n + 1;
int que[MAXH], depth[MAXH];

bool bfs() {
    int front = 0, rear = 1;
    memset(depth, -1, sizeof(depth));
    que[0] = src;
    depth[src] = 0;
    while (front < rear) {
        int u = que[front++];
        for (int i = head[u]; i != -1; i = edge[i].next) {
            if (edge[i].f) {
                int v = edge[i].v;
                if (depth[v] == -1) {
                    depth[v] = depth[u] + 1;
                    que[rear++] = v;
                }
            }
        }
    }
    return depth[dst] >= 0;
}

int dinic(int u, int sum) {
    if (u == dst) {
        return sum;
    }
    int temp = sum;
    for (int i = head[u]; i != -1 && sum; i = edge[i].next) {
        if (edge[i].f) {
            int v = edge[i].v;
            if (depth[v] == depth[u] + 1) {
                int f = dinic(v, min(sum, edge[i].f));
                edge[i].f -= f;
                edge[i ^ 1].f += f;
                sum -= f;
            }
        }
    }
    return temp - sum;
}

int maxFlow() {
    int ret = 0;
    while (bfs()) {
        ret += dinic(src, 0x3f3f3f3f);
    }
    return ret;
}

int ans[MAXN];

int main() {
    int u, v;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    src = 0;
    dst = 2 * n + 1;
    clearEdge();
    int sumA = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        addEdge(src, i, a[i]);
        addEdge(i, n + i, a[i]);
        sumA += a[i];
    }
    int sumB = 0;
    for (int j = 1; j <= n; ++j) {
        cin >> b[j];
        addEdge(n + j, dst, b[j]);
        sumB += b[j];
    }
    while (m--) {
        cin >> u >> v;
        addEdge(u, n + v, a[u]);
        addEdge(v, n + u, a[v]);
    }
    bool valid = sumA == sumB and maxFlow() == sumB;
    if (valid) {
        cout << "YES" << endl;
        for (int u = 1; u <= n; ++u) {
            memset(ans, 0, sizeof(ans));
            for (int i = head[u]; i != -1; i = edge[i].next) {
                int v = edge[i].v;
                if (n < v and v <= (n << 1)) {
                    ans[v - n] = a[u] - edge[i].f;
                }
            }
            for (int v = 1; v <= n; ++v) {
                cout << ans[v] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
