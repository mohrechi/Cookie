#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
const int MAXM = MAXN * 2;

int n, m, q;
int u[MAXN], v[MAXN];

class Graph {
public:
    Graph() : edgeNum(2) {
    }
    inline void addEdge(int u, int v) {
        addEdgeSub(u, v);
        addEdgeSub(v, u);
    }
    inline int first(int u) {
        return head[u];
    }
    inline int next(int i) {
        return edge[i].next;
    }
    inline int v(int i) {
        return edge[i].v;
    }
    inline bool hasNext(int i) {
        return i;
    }
    inline void setBridge(int i) {
        edge[i].bridge = edge[i ^ 1].bridge = true;
    }
    inline bool isBridge(int i) {
        return edge[i].bridge;
    }
private:
    int head[MAXN];
    int edgeNum;
    struct Edge {
        int v, next;
        bool bridge;
    } edge[MAXM];
    inline void addEdgeSub(int u, int v) {
        edge[edgeNum] = {v, head[u], false};
        head[u] = edgeNum++;
    }
} origin, reduced;

int s[MAXN], d[MAXN];

int stk[MAXN], top, stamp;
bool visit[MAXN];
int dfn[MAXN], low[MAXN];
int color[MAXN], colorNum;

void tarjan(int u, int f) {
    dfn[u] = low[u] = ++stamp;
    visit[u] = true;
    stk[top++] = u;
    for (int i = origin.first(u); origin.hasNext(i); i = origin.next(i)) {
        int v = origin.v(i);
        if ((i ^ 1) == f) {
            continue;
        }
        if (dfn[v] == 0) {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                origin.setBridge(i);
            }
        } else if (visit[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u]) {
        int t;
        do {
            t = stk[--top];
            visit[t] = false;
        } while (t != u);
    }
}

void tarjan() {
    for (int i = 1; i <= n; ++i) {
        if (dfn[i] == 0) {
            tarjan(i, 0);
        }
    }
}

void dye(int u, int f, int c) {
    visit[u] = true;
    color[u] = c;
    for (int i = origin.first(u); origin.hasNext(i); i = origin.next(i)) {
        int v = origin.v(i);
        if (v == f or origin.isBridge(i) or visit[v]) {
            continue;
        }
        dye(v, u, c);
    }
}

void dye() {
    memset(visit, false, sizeof(visit));
    for (int i = 1; i <= n; ++i) {
        if (not visit[i]) {
            dye(i, 0, ++colorNum);
        }
    }
}

void reduce() {
    set<pair<int, int>> pairs;
    for (int i = 0; i < m; ++i) {
        int cu = color[u[i]];
        int cv = color[v[i]];
        if (cu == cv) {
            continue;
        }
        pair<int, int> p = {cu, cv};
        if (pairs.find(p) == pairs.end()) {
            pairs.insert(p);
            reduced.addEdge(cu, cv);
        }
    }
}

int depth[MAXN], parent[MAXN][20];

void initParents(int u, int f, int d) {
    visit[u] = true;
    depth[u] = d;
    parent[u][0] = f;
    for (int i = 1; parent[parent[u][i - 1]][i - 1]; ++i) {
        parent[u][i] = parent[parent[u][i - 1]][i - 1];
    }
    for (int i = reduced.first(u); reduced.hasNext(i); i = reduced.next(i)) {
        int v = reduced.v(i);
        if (v != f) {
            initParents(v, u, d + 1);
        }
    }
}

void initParents() {
    memset(visit, false, sizeof(visit));
    for (int i = 1; i <= n; ++i) {
        if (not visit[i]) {
            initParents(i, 0, 0);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) {
        swap(u, v);
    }
    if (depth[u] < depth[v]) {
        int dist = depth[v] - depth[u];
        for (int i = 0; i < 20; ++i) {
            if (dist & (1 << i)) {
                v = parent[v][i];
            }
        }
    }
    if (u != v) {
        for (int i = 19; i >= 0; --i) {
            if (parent[u][i] != parent[v][i]) {
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        u = parent[u][0];
        v = parent[v][0];
        if (u != v) {
            return 0;
        }
    }
    return u;
}

int sendNum[MAXN], receiveNum[MAXN], commonNum[MAXN];

bool initNumbers() {
    for (int i = 0; i < q; ++i) {
        int cs = color[s[i]];
        int cd = color[d[i]];
        ++sendNum[cs];
        ++receiveNum[cd];
        int common = lca(cs, cd);
        if (common == 0) {
            return false;
        }
        ++commonNum[common];
    }
    return true;
}

bool check(int u, int f) {
    visit[u] = true;
    for (int i = reduced.first(u); reduced.hasNext(i); i = reduced.next(i)) {
        int v = reduced.v(i);
        if (v != f) {
            if (not check(v, u)) {
                return false;
            }
            sendNum[u] += sendNum[v];
            receiveNum[u] += receiveNum[v];
            commonNum[u] += commonNum[v];
        }
    }
    if (sendNum[u] > commonNum[u] and receiveNum[u] > commonNum[u]) {
        return false;
    }
    return true;
}

bool check() {
    memset(visit, false, sizeof(visit));
    for (int i = 1; i <= n; ++i) {
        if (not visit[i]) {
            if (not check(i, 0)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u[i], &v[i]);
        origin.addEdge(u[i], v[i]);
    }
    for (int i = 0; i < q; ++i) {
        scanf("%d%d", &s[i], &d[i]);
    }
    tarjan();
    dye();
    reduce();
    initParents();
    puts((initNumbers() and check()) ? "Yes" : "No");
    return 0;
}
