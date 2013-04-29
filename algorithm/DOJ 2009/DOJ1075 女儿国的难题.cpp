#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 505;

int x, y;
bool graph[MAXN][MAXN];

bool visit[MAXN];
int link[MAXN];

bool find(int u)
{
    for(int v=1;v<=y;++v)
    {
        if(graph[u][v] && !visit[v])
        {
            visit[v] = true;
            if(link[v] == -1 || find(link[v]))
            {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungray()
{
    int ans = 0;
    memset(link, -1, sizeof(link));
    for(int i=1;i<=x;++i)
    {
        memset(visit, false, sizeof(visit));
        if(find(i))
        {
            ++ ans;
        }
    }
    return ans;
}

int main()
{
    int u, v, t;
    while(~scanf("%d%d", &x, &y))
    {
        memset(graph, true, sizeof(graph));
        for(int u=1;u<=x;++u)
        {
            scanf("%d", &t);
            while(t--)
            {
                scanf("%d", &v);
                graph[u][v] = false;
            }
        }
        printf("%d\n", hungray());
    }
    return 0;
}
