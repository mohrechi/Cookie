#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200;

int n;
bool map[MAXN][MAXN];
int path[MAXN], pathNumber;
bool visit[MAXN];

struct Edge
{
    int v, next;
}edge[MAXN * MAXN];
int edgeNumber, head[MAXN];

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

bool dfs(int u, int father, int depth)
{
    if(depth == n)
    {
        return map[u][1];
    }
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        path[depth] = v;
        if(v != father && !visit[v])
        {
            visit[v] = true;
            if(dfs(v, u, depth + 1))
            {
                return true;
            }
            visit[v] = false;
        }
    }
    return false;
}

/*
void reverse(int start, int end)
{
    while(start < end)
    {
        swap(path[start], path[end]);
        ++ start;
        -- end;
    }
}

void hamilton()
{
    pathNumber = 0;
    memset(visit, false, sizeof(visit));
    int u = 1, v;
    for(v=2;v<=n;++v)
    {
        if(map[u][v])
        {
            break;
        }
    }
    visit[u] = visit[v] = true;
    path[pathNumber++] = u;
    path[pathNumber++] = v;
    while(true)
    {
        while(true)
        {
            int i;
            for(i=1;i<=n;++i)
            {
                if(map[v][i] && !visit[i])
                {
                    path[pathNumber++] = i;
                    visit[i] = true;
                    v = i;
                    break;
                }
            }
            if(i > n)
            {
                break;
            }
        }
        reverse(0, pathNumber - 1);
        swap(u, v);
        while(true)
        {
            int i;
            for(i=1;i<=n;++i)
            {
                if(map[v][i] && !visit[i])
                {
                    path[pathNumber++] = i;
                    visit[i] = true;
                    v = i;
                    break;
                }
            }
            if(i > n)
            {
                break;
            }
        }
        if(!map[u][v])
        {
            int i;
            for(i=1;i<pathNumber-2;++i)
            {
                if(map[path[i]][v] && map[path[i+1]][u])
                {
                    break;
                }
            }
            v = path[i+1];
            reverse(i+1, pathNumber-1);
        }
        if(pathNumber == n)
        {
            break;
        }
        int i, j;
        for(i=1;i<=n;++i)
        {
            if(!visit[i])
            {
                for(j=1;j<pathNumber-1;++j)
                {
                    if(map[i][path[j]])
                    {
                        u = path[j-1];
                        v = i;
                        reverse(0, j-1);
                        reverse(j, pathNumber-1);
                        path[pathNumber++] = i;
                        visit[i] = true;
                        break;
                    }
                }
                if(map[i][path[j]])
                {
                    break;
                }
            }
        }
    }
}
*/
int main()
{
    int m, u, v;
    while(~scanf("%d%d",&n,&m))
    {
        memset(map, false, sizeof(map));
        edgeNumber = 0;
        memset(head, -1, sizeof(head));
        memset(visit, false, sizeof(visit));
        while(m--)
        {
            scanf("%d%d", &u, &v);
            map[u][v] = map[v][u] = true;
            addEdge(u, v);
            addEdge(v, u);
        }
        visit[1] = true;
        path[0] = 1;
        dfs(1, -1, 1);
        for(int i=0;i<n;++i)
        {
            if(i)
            {
                printf(" ");
            }
            printf("%d", path[i]);
        }
        printf("\n");
        /*hamilton();
        for(int i=0;i<pathNumber;++i)
        {
            if(i)
            {
                printf(" ");
            }
            printf("%d", path[i]);
        }
        printf("\n");*/
    }
    return 0;
}
