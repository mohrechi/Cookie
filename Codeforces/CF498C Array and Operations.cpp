#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
const int MAXM = 2 * MAXN * (log(MAXN) / log(2)) + 10;
const int MAXE = MAXM * MAXM;
const int MAXP = 1e5;

int n, m, a[MAXN];
struct Edge {
    int u, v, f, next;
} edge[MAXE];
int head[MAXM], edgeNum;
int src, dst;

inline void clearEdge() {
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int f) {
    edge[edgeNum] = {u, v, f, head[u]};
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int f) {
    addEdgeSub(u, v, f);
    addEdgeSub(v, u, 0);
}

map<pair<int, int>, int> idx;

inline bool exists(int i, int p) {
    return idx.find({i, p}) != idx.end();
}

inline int getIdx(int i, int p) {
    static int id = 1;
    auto it = idx.find({i, p});
    if (it != idx.end()) {
        return it->second;
    }
    idx[{i, p}] = ++id;
    return id;
}

bool isPrime[MAXP];
int prime[MAXP], primeNum;

void initPrime() {
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 2; i < MAXP; ++i) {
        if (isPrime[i]) {
            prime[primeNum++] = i;
            for (int j = i + i; j < MAXP; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int factor[MAXN][MAXN], factorCnt[MAXN][MAXN], factorNum[MAXN];

void decompose(int idx, int x) {
    for (int i = 0; i < primeNum && prime[i] <= x; ++i) {
        if (x % prime[i] == 0) {
            factor[idx][factorNum[idx]] = prime[i];
            while (x % prime[i] == 0) {
                ++factorCnt[idx][factorNum[idx]];
                x /= prime[i];
            }
            ++factorNum[idx];
        }
    }
    if (x > 1) {
        factor[idx][factorNum[idx]] = x;
        factorCnt[idx][factorNum[idx]] = 1;
        ++factorNum[idx];
    }
}

int que[MAXM], depth[MAXM];

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

int main() {
    int u, v;
    initPrime();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        decompose(i, a[i]);
    }
    clearEdge();
    src = 0, dst = 1;
    for (int i = 1; i <= n; ++i) {
        if (i & 1) {
            for (int j = 0; j < factorNum[i]; ++j) {
                addEdge(src, getIdx(i, factor[i][j]), factorCnt[i][j]);
            }
        } else {
            for (int j = 0; j < factorNum[i]; ++j) {
                addEdge(getIdx(i, factor[i][j]), dst, factorCnt[i][j]);
            }
        }
    }
    while (m--) {
        scanf("%d%d", &u, &v);
        if (v & 1) {
            swap(u, v);
        }
        for (int i = 0, j = 0; i < factorNum[u] && j < factorNum[v]; ++i) {
            while (factor[v][j] < factor[u][i]) {
                ++j;
            }
            if (factor[v][j] != factor[u][i]) {
                continue;
            }
            int ui = getIdx(u, factor[u][i]);
            int vi = getIdx(v, factor[v][j]);
            int fi = min(factorCnt[u][i], factorCnt[v][j]);
            addEdge(ui, vi, fi);
        }
    }
    printf("%d\n", maxFlow());
    return 0;
}
