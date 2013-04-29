#include <cstdio>
#include <cstring>
static const int MAXN = 1005;
static const int MAXM = 10005;

bool graph[MAXN][MAXN];
bool visited[MAXN];
int cnt[MAXN];
int n,m;

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
        if(cnt[i] != 0 && !visited[i])
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    int a,b;
    while(~scanf("%d%d",&n,&m))
    {
        memset(graph, false, sizeof(graph));
        memset(cnt, 0, sizeof(cnt));
        memset(visited, false, sizeof(visited));
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&a,&b);
            graph[a][b] = graph[b][a] = true;
            ++cnt[a], ++cnt[b];
        }
        bool flag = true;
        for(int i=1;i<=n;++i)
        {
            if(cnt[i]&1)
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            search(1);
            flag = find();
        }
        if(flag)
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
