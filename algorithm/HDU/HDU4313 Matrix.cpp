#include <cstdio>
#include <cstring>
const int MAXN = 100005;
const __int64 INF = 10000000000000000LL;

__int64 dp[MAXN][2];
int n, k;

struct Edge
{
    int v, w, next;
}edge[MAXN * 2];
int edgeNumber, head[MAXN];
bool haveMachine[MAXN];

inline void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

inline __int64 min(const __int64 &x, const __int64 &y)
{
    return x < y ? x : y;
}

void dfs(int u, int father)
{
    if(haveMachine[u])
    {
        dp[u][0] = INF;
        dp[u][1] = 0;
    }
    else
    {
        dp[u][0] = 0;
        dp[u][1] = INF;
    }
    __int64 minS = INF;
    __int64 count = 0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        int w = edge[i].w;
        if(v != father)
        {
            dfs(v, u);
            if(haveMachine[u])
            {
                dp[u][1] += min(dp[v][0], dp[v][1] + w);
            }
            else
            {
                dp[u][0] += min(dp[v][0], dp[v][1] + w);
                ++ count;
                if(dp[v][0] <= dp[v][1] + w)
                {
                    if(minS > dp[v][1] - dp[v][0])
                    {
                        minS = dp[v][1] - dp[v][0];
                    }
                }
                else
                {
                    if(minS > - w)
                    {
                        minS = - w;
                    }
                }
            }
        }
    }
    if(!haveMachine[u] && count)
    {
        dp[u][1] = dp[u][0] + minS;
    }
}

int main()
{
    int t;
    int x, y, z;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);
        edgeNumber = 0;
        memset(head, -1, sizeof(head));
        for(int i=1;i<n;++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            addEdge(x, y, z);
            addEdge(y, x, z);
        }
        memset(haveMachine, false, sizeof(haveMachine));
        for(int i=0;i<k;++i)
        {
            scanf("%d", &x);
            haveMachine[x] = true;
        }
        dfs(0, -1);
        if(haveMachine[0])
        {
            printf("%I64d\n", dp[0][1]);
        }
        else
        {
            printf("%I64d\n", min(dp[0][0], dp[0][1]));
        }
    }
    return 0;
}
