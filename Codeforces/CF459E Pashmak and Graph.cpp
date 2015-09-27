#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;

int n, m;
struct Edge {
    int u, v, w;
    bool operator <(const Edge &edge) const {
        return w < edge.w;
    }
} edge[MAXN];

int len[2][MAXN];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    sort(edge, edge + m);
    int prev = 0, curr = 1;
    vector<int> vs;
    for (int i = 0; i < m; ++i) {
        if (i && edge[i].w != edge[i - 1].w) {
            swap(prev, curr);
            for (auto v : vs) {
                len[curr][v] = len[prev][v];
            }
            vs.clear();
        }
        vs.push_back(edge[i].v);
        len[curr][edge[i].v] = max(len[curr][edge[i].v], len[prev][edge[i].u] + 1);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans = max(ans, len[curr][i]);
    }
    printf("%d\n", ans);
    return 0;
}
