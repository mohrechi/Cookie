#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int INF = 1000000000;

int n, a[MAXN], b[MAXN];
int g[MAXN][MAXN];
int dp[MAXN][2][2];

inline void addEdge(const int &u, const int &v)
{
    g[u][++g[u][0]] = v;
}

void dfs(int u, int father)
{
    if(g[u][0] == 1 && father != -1)
    {
        dp[u][0][0] = a[u] >> 1;
        dp[u][1][0] = b[u] >> 1;
        dp[u][0][1] = a[u];
        dp[u][1][1] = b[u];
    }
    else
    {
        int sa = 0, sb = 0;
        int da = INF, db = INF;
        for(int i=1;i<=g[u][0];++i)
        {
            int v = g[u][i];
            if(v != father)
            {
                dfs(v, u);
                sa += min(dp[v][0][0], dp[v][1][1]);
                sb += min(dp[v][1][0], dp[v][0][1]);
                da = min(da, dp[v][0][1] - min(dp[v][0][0], dp[v][1][1]));
                db = min(db, dp[v][1][1] - min(dp[v][1][0], dp[v][0][1]));
            }
        }
        dp[u][0][0] = sa + (a[u] >> 1);
        dp[u][1][0] = sb + (b[u] >> 1);
        dp[u][0][1] = min(sa + a[u], sa + (a[u] >> 1) + da);
        dp[u][1][1] = min(sb + b[u], sb + (b[u] >> 1) + db);
    }
}

int main()
{
    int u, v;
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
        }
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &b[i]);
        }
        memset(g, 0, sizeof(g));
        for(int i=1;i<n;++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        dfs(1, -1);
        printf("%d\n", min(dp[1][0][1], dp[1][1][1]));
    }
    return 0;
}
