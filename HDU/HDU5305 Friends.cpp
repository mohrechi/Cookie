#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m;
int edge[10][10], edgeNum[10];
int num[10];

int dfs(int u, int idx) {
    if (u > n) {
        return 1;
    }
    if (idx == edgeNum[u]) {
        if (num[u] == 0) {
            return dfs(u + 1, 0);
        }
        return 0;
    }
    int v = edge[u][idx], ret = 0;
    ++num[u];
    ++num[v];
    ret = dfs(u, idx + 1);
    num[u] -= 2;
    num[v] -= 2;
    ret += dfs(u, idx + 1);
    ++num[u];
    ++num[v];
    return ret;
}

int main() {
    int T, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(edgeNum, 0, sizeof(edgeNum));
        for (int i = 0; i < m; ++i) {
            scanf("%d%d", &u, &v);
            if (u > v) {
                swap(u, v);
            }
            edge[u][edgeNum[u]++] = v;
        }
        printf("%d\n", dfs(1, 0));
    }
    return 0;
}
