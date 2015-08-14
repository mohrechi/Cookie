#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500000 + 10;

int n, m;
char s[MAXN];
struct Edge {
    int v, next;
} edge[MAXN];
int head[MAXN], edgeNum;

inline void clearEdge() {
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v) {
    edge[edgeNum] = {v, head[u]};
    head[u] = edgeNum++;
}

int depth[MAXN], idL[MAXN], idR[MAXN], id;
vector<int> layer[MAXN];
vector<int> sum[MAXN];

void dfs(int u, int d) {
    depth[u] = d;
    idL[u] = idR[u] = ++id;
    layer[d].push_back(id);
    int idx = (int)sum[d].size();
    sum[d].push_back(0);
    sum[d][idx] |= (1 << (s[u] - 'a'));
    if (idx) {
        sum[d][idx] ^= sum[d][idx - 1];
    }
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].v;
        dfs(v, d + 1);
        idR[u] = max(idR[u], idR[v]);
    }
}

int main() {
    int f, v, d;
    scanf("%d%d", &n, &m);
    clearEdge();
    for (int i = 2; i <= n; ++i) {
        scanf("%d", &f);
        addEdge(f, i);
    }
    scanf("%s", s + 1);
    dfs(1, 1);
    while (m--) {
        scanf("%d%d", &v, &d);
        int l, r, n = (int)layer[d].size();
        int ll = n, rr = -1;
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (layer[d][mid] >= idL[v]) {
                r = mid - 1;
                ll = min(ll, mid);
            } else {
                l = mid + 1;
            }
        }
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (layer[d][mid] <= idR[v]) {
                l = mid + 1;
                rr = max(rr, mid);
            } else {
                r = mid - 1;
            }
        }
        int sumT = 0;
        if (ll <= rr) {
            sumT = sum[d][rr];
            if (ll) {
                sumT ^= sum[d][ll - 1];
            }
        }
        puts(__builtin_popcount(sumT) <= 1 ? "Yes" : "No");
    }
    return 0;
}
