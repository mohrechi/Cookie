#include <cstdio>
#include <cstdlib>
static const int MAXN = 105;
static const int INF = 1000000000;
int graph[MAXN][MAXN];
int n, ans;
int main(int argc, char *argv[])
{
    char temp[128];
    scanf("%d",&n);
    for(int i=1;i<n;++i)
    {
        for(int j=0;j<i;++j)
        {
            scanf("%s",temp);
            if(*temp == 'x')
            {
                graph[j][i] = graph[i][j] = INF;
            }
            else
            {
                graph[i][j] = graph[j][i] = atoi(temp);
            }
        }
    }
    for(int k=0;k<n;++k)
    {
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(graph[i][j] > graph[i][k] + graph[k][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        if(ans < graph[0][i])
        {
            ans = graph[0][i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
