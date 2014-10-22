#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;

int n;
bool graph[MAXN][MAXN];
bool visit[MAXN];

int dfs(int u)
{
    visit[u] = true;
    for (int i = 1; i <= n; ++i)
    {
        if (graph[u][i] && !visit[i])
        {
            if (dfs(i) == 0)
            {
                visit[u] = false;
                return i;
            }
        }
    }
    visit[u] = false;
    return 0;
}

int main()
{
    int s, u, v;
    while (~scanf("%d%d", &n, &s))
    {
        memset(graph, false, sizeof(graph));
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &u, &v);
            graph[u][v] = graph[v][u] = true;
        }
        memset(visit, false, sizeof(visit));
        int ans = dfs(s);
        if (ans)
        {
            printf("First player wins flying to airport %d\n", ans);
        }
        else
        {
            puts("First player loses");
        }
    }
    return 0;
}
