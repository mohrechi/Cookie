#include <cstdio>
#include <cstring>
static const int MAXN = 1005;

inline int abs(int x)
{
    return x>=0?x:-x;
}

inline int max(int x, int y)
{
    return x>y?x:y;
}

inline int max(int x, int y, int z)
{
    return max(x, max(y, z));
}

struct Point
{
    int x, y, c;
    void input()
    {
        scanf("%d%d%d", &x, &y, &c);
    }
    bool isConnect(const Point &p)
    {
        return abs(x - p.x) + abs(y - p.y) == 1;
    }
}point[MAXN];
int n;

struct Edge
{
    int v, next;
}edge[MAXN * 10];
int edgeNumber, head[MAXN];
int dp[MAXN][2];

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void dfs(int x, int father)
{
    dp[x][0] = 0;
    dp[x][1] = point[x].c;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if(edge[i].v != father)
        {
            dfs(edge[i].v, x);
            dp[x][0] = max(dp[x][0], dp[edge[i].v][0], dp[edge[i].v][1]);
            if(dp[edge[i].v][1] > 0)
            {
                dp[x][1] += dp[edge[i].v][1];
            }
        }
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            point[i].input();
        }
        edgeNumber = 0;
        memset(head, -1, sizeof(head));
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(point[i].isConnect(point[j]))
                {
                    addEdge(i, j);
                    addEdge(j, i);
                }
            }
        }
        dfs(0, -1);
        printf("%d\n", max(dp[0][0], dp[0][1]));
    }
    return 0;
}
