#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 2;

int n, m;
bool visit[MAXN];
bool edge[MAXN][MAXN];

void dfs(int u) {
    visit[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (edge[u][v] and not visit[v]) {
            dfs(v);
        }
    }
}

int main() {
    int u, v;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v;
        edge[u][v] = edge[v][u] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (not visit[i]) {
            ++m;
            dfs(i);
        }
    }
    cout << (1LL << (n - m - 1)) << endl;
    return 0;
}
