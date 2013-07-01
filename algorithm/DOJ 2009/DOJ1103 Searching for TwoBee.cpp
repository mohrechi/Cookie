#include <cstdio>
#include <cstring>
static const int MAXN = 1005;
int n,m;
bool visited[MAXN];
bool graph[MAXN][MAXN];

void search(int x)
{
    if(!visited[x])
    {
        visited[x] = true;
        for(int i=1;i<=n;++i)
        {
            if(graph[x][i])
            {
                search(i);
            }
        }
    }
}

bool find()
{
    for(int i=1;i<=n;++i)
    {
        if(!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(graph, false, sizeof(graph));
        memset(visited, false, sizeof(visited));
        int a,b;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&a,&b);
            graph[a][b] = graph[b][a] = true;
        }
        search(1);
        if(find())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
