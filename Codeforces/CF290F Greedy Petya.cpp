#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;

int n, m;
int degree[MAXN];
vector<int> graph[MAXN];
bool edge[MAXN][MAXN];
bool visit[MAXN];

void init() {
    memset(degree, 0, sizeof(degree));
    for (int i = 0; i < MAXN; ++i) {
        graph[i].clear();
    }
    memset(edge, false, sizeof(edge));
}

bool compare(int u, int v) {
    if (degree[u] != degree[v]) {
        return degree[u] < degree[v];
    }
    return u < v;
}

void dfs(int u) {
    visit[u] = true;
    for(int i = 0; i < (int)graph[u].size(); ++i) {
        if(!visit[graph[u][i]]) {
            dfs(graph[u][i]);
            return;
        }
    }
}

bool check() {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += visit[i];
    }
    return ans == n;
}

int main() {
    int u, v;
    bool flag = false;
    scanf("%d %d", &n, &m);
    init();
    while (m--) {
        scanf("%d %d", &u, &v);
        u--, v--;
        if (u == v) {
            continue;
        }
        if (edge[u][v]) {
            continue;
        }
        graph[u].push_back(v);
        graph[v].push_back(u);
        edge[u][v] = edge[v][u] = true;
        degree[u]++, degree[v]++;
    }
    for (int i = 0; i < n; ++i) {
        sort(graph[i].begin(), graph[i].end(), compare);
    }
    flag = false;
    for (int i = 0; i < n; ++i) {
        memset(visit, false, sizeof(visit));
        dfs(i);
        if (check()) {
            printf("Yes\n");
            flag = true;
            break;
        }
    }
    if (!flag) {
        printf("No\n");
    }
    return 0;
}
