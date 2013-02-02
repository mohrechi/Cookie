#include <cstdio>
#include <cstring>
static const int MAXN = 35;

char name[MAXN][MAXN];
int n, m;
double graph[MAXN][MAXN];

int findPos(const char *s)
{
    for(int i=0;i<n;++i)
    {
        if(strcmp(s, name[i]) == 0)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    char s1[MAXN], s2[MAXN];
    double rate;
    int u, v, cas = 0;
    while(scanf("%d", &n), n)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%s", name[i]);
            for(int j=0;j<n;++j)
            {
                graph[i][j] = 0.0;
            }
        }
        scanf("%d", &m);
        while(m--)
        {
            scanf("%s%lf%s", s1, &rate, s2);
            u = findPos(s1);
            v = findPos(s2);
            if(rate > graph[u][v])
            {
                graph[u][v] = rate;
            }
        }
        for(int i=0;i<n;++i)
        {
            if(graph[i][i] < 1.0)
            {
                graph[i][i] = 1.0;
            }
        }
        for(int k=0;k<n;++k)
        {
            for(int i=0;i<n;++i)
            {
                for(int j=0;j<n;++j)
                {
                    if(graph[i][j] < graph[i][k] * graph[k][j])
                    {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }
        printf("Case %d: ", ++cas);
        int i;
        for(i=0;i<n;++i)
        {
            if(graph[i][i] > 1.000001)
            {
                break;
            }
        }
        if(i<n)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
