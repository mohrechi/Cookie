#include <cstdio>
static const int MAXN = 105;
static const int MAXM = 10005;
static const int INF = 0xFFFFFFF;
int n, m;

int mini[MAXN][MAXN], dist[MAXN][MAXN];
int path[MAXN][MAXN], result[MAXN], resultNumber;

void record(int i, int j, int k)
{
    for(resultNumber=0;i!=j;j=path[i][j])
    {
        result[resultNumber++] = j;
    }
    result[resultNumber++] = i;
    result[resultNumber++] = k;
}

bool floyd()
{
    int minDist = INF;
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<k;++i)
        {
            for(int j=i+1;j<k;++j)
            {
                if(minDist > mini[i][k] + mini[k][j] + dist[i][j])
                {
                    minDist = mini[i][k] + mini[k][j] + dist[i][j];
                    record(i, j, k);
                }
            }
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[k][j];
                }
            }
        }
    }
    return minDist != INF;
}

int main(int argc, char *argv[])
{
    int u, v, w;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            dist[i][j] = mini[i][j] = (i==j?0:INF);
            path[i][j] = i;
        }
    }
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d%d",&u,&v,&w);
        if(w < mini[u][v])
        {
            dist[u][v] = dist[v][u] = mini[u][v] = mini[v][u] = w;
        }
    }
    if(floyd())
    {
        for(--resultNumber;resultNumber>=0;--resultNumber)
        {
            printf("%d%c", result[resultNumber], resultNumber?' ':'\n');
        }
    }
    else
    {
        printf("No solution.\n");
    }
    return 0;
}
