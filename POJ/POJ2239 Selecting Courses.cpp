#include <cstdio>
#include <cstring>
static const int MAXN = 500;
static const int MAXT = 7 * 12;
int m;
bool graph[MAXN][MAXN];
bool visited[MAXN];
int link[MAXN];

bool find(int a)
{
    for(int i=1;i<=m;i++)
    {
        if(graph[a][i] && !visited[i])
        {
            visited[i] = true;
            if(link[i] == 0 || find(link[i]))
            {
                link[i] = a;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int ans=0;
    memset(link, 0, sizeof(link));
    for(int i=1;i<=MAXT;i++)
    {
        memset(visited, false, sizeof(visited));
        if(find(i))
        {
            ++ans;
        }
    }
    return ans;
}


int main()
{
    int t, p, q, u, v;
    while(~scanf("%d",&m))
    {
        memset(graph, false, sizeof(graph));
        for(int i=1;i<=m;++i)
        {
            scanf("%d", &t);
            while(t--)
            {
                scanf("%d%d",&p,&q);
                graph[(p - 1) * 12 + q][i] = true;
            }
        }
        printf("%d\n", hungary());
    }
    return 0;
}
