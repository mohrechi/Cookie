#include <cstdio>
#include <cstring>
static const int MAXN = 105;
int n, reach[MAXN][MAXN], graph[MAXN][MAXN];
int value[MAXN], dist[MAXN];

int main()
{
    int m, t;
    while(scanf("%d",&n), n+1)
    {
        memset(graph, false, sizeof(graph));
        memset(reach, false, sizeof(reach));
        memset(dist, -1, sizeof(dist));
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d", &value[i], &m);
            while(m--)
            {
                scanf("%d",&t);
                graph[i][t] = reach[i][t] = true;
            }
        }
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(reach[i][k] && reach[k][j])
                    {
                        reach[i][j] = true;
                    }
                }
            }
        }
        reach[n][n] = true;
        if(!reach[1][n])
        {
            printf("hopeless\n");
            continue;
        }
        dist[1] = 100;
        int k;
        for(k=0;k<n;++k)
        {
            bool flag = true;
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    if(graph[i][j])
                        if(dist[i] != -1)
                            if(reach[j][n])
                                if(dist[j] < dist[i] + value[j])
                                {
                                    dist[j] = dist[i] + value[j];
                                    flag = false;
                                }
            if(flag)
                break;
        }
        if(k >= n || dist[n] > 0)
            printf("winnable\n");
        else
            printf("hopeless\n");
    }
    return 0;
}
