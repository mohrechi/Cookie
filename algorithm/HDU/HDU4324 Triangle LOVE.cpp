#include <cstdio>
#include <cstring>
const int MAXN = 2005;

struct Edge
{
    int v, next;
}edge[MAXN * MAXN];
int edgeNumber, head[MAXN];
int n;

inline int min(int x, int y)
{
    return x < y ? x : y;
}

inline void initEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

bool visit[MAXN];
bool record[MAXN][MAXN];

bool dfs(int u, int depth)
{
    if(visit[u])
    {
        if(depth > 2)
        {
            if(record[depth - 3][u])
            {
                return true;
            }
        }
        return false;
    }
    else
    {
        visit[u] = true;
        record[depth][u] = true;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            if(dfs(edge[i].v, depth + 1))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int t;
    char s[MAXN];
    scanf("%d", &t);
    for(int k=1;k<=t;++k)
    {
        scanf("%d", &n);
        initEdge();
        for(int i=0;i<n;++i)
        {
            scanf("%s", s);
            for(int j=0;j<n;++j)
            {
                if(s[j] == '1')
                {
                    addEdge(i, j);
                }
            }
        }
        bool flag = false;
        memset(visit, false, sizeof(visit));
        memset(record, false, sizeof(record));
        for(int i=0;i<n && !flag;++i)
        {
            if(!visit[i])
            {
                if(dfs(i, 0))
                {
                    flag = true;
                    break;
                }
            }
        }
        printf("Case #%d: ", k);
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
