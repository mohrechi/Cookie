#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n;
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

int init[MAXN], goal[MAXN];

vector<int> ans;

void dfs(int u, int p, int a, int b) {
    if ((init[u] ^ goal[u] ^ b) != 0) {
        ans.push_back(u);
        b ^= 1;
    }
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int& v = edge[i].v;
        if (v != p) {
            dfs(v, u, b, a);
        }
    }
}

int main() {
    int u, v;
    scanf("%d", &n);
    clearEdge();
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &init[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &goal[i]);
    }
    dfs(1, 0, 0, 0);
    printf("%d\n", (int)ans.size());
    for (auto a : ans) {
        printf("%d\n", a);
    }
    return 0;
}
