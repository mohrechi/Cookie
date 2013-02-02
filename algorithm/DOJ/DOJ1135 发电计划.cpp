#include <cstdio>
#include <cstring>
static const int MAXN = 50005;
int n, cost[MAXN];

struct Edge
{
    int v, next;
}edge[MAXN * 2];
int edgeNumber, head[MAXN];
int dp[MAXN][3];

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

inline int min(int x, int y)
{
    return x < y ? x : y;
}

inline int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

void dfs(int index, int father)
{
    bool flag = true;
    for(int i=head[index];i!=-1;i=edge[i].next)
    {
        if(edge[i].v != father)
        {
            flag = false;
            dfs(edge[i].v, index);
        }
    }
    if(flag)
    {
        dp[index][0] = cost[index];
        dp[index][1] = 1000000000;
        dp[index][2] = 0;
    }
    else
    {
        dp[index][0] = cost[index];
        dp[index][1] = 0;
        dp[index][2] = 0;
        int dflag = 1, minCost = 1000000000, select;
        for(int i=head[index];i!=-1;i=edge[i].next)
        {
            if(edge[i].v != father)
            {
                dp[index][0] += min(dp[edge[i].v][0], dp[edge[i].v][1], dp[edge[i].v][2]);
                dp[index][1] += min(dp[edge[i].v][0], dp[edge[i].v][1]);
                dp[index][2] += min(dp[edge[i].v][0], dp[edge[i].v][1]);
                if(dp[edge[i].v][0] <= dp[edge[i].v][1])
                {
                    dflag = 0;
                }
                if(minCost > dp[edge[i].v][0] - dp[edge[i].v][1])
                {
                    minCost = dp[edge[i].v][0] - dp[edge[i].v][1];
                }
            }
        }
        if(dflag)
        {
            dp[index][1] += minCost;
        }
    }
}

int main()
{
    int u, v;
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &cost[i]);
        }
        memset(head, -1, sizeof(head));
        edgeNumber = 0;
        for(int i=1;i<n;++i)
        {
            scanf("%d%d",&u,&v);
            addEdge(u, v);
            addEdge(v, u);
        }
        dfs(0, -1);
        printf("%d\n", min(dp[0][0], dp[0][1]));
    }
    return 0;
}
