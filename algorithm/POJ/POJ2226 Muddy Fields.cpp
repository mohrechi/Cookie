#include <cstdio>
#include <cstring>

static const int MAXN = 51;

int r, c;
int cx, cy;
char muddy[MAXN][MAXN];
int a[MAXN][MAXN], b[MAXN][MAXN];
struct Edge
{
    int v, next;
}edge[MAXN*MAXN*2];
int edgeNumber;
int head[MAXN*MAXN];
int link[MAXN*MAXN];
bool visited[MAXN*MAXN];

void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void make()
{
    cx = 0, cy = 0;
    edgeNumber = 1;
    memset(head, 0, sizeof(head));
    for(int i=1;i<=r;++i)
        for(int j=1;j<=c;++j)
            if(muddy[i][j] == '*')
                if(muddy[i][j-1] == '*')
                    a[i][j] = a[i][j-1];
                else
                    a[i][j] = ++cx;
    for(int j=1;j<=c;++j)
        for(int i=1;i<=r;++i)
            if(muddy[i][j] == '*')
            {
                if(muddy[i-1][j] != '*')
                    ++cy;
                addEdge(a[i][j], cy);
            }

}

bool dfs(int x)
{
    for(int i = head[x]; i; i = edge[i].next)
    {
        if(!visited[edge[i].v])
        {
            visited[edge[i].v] = true;
            if(link[edge[i].v] == -1 || dfs(link[edge[i].v]))
            {
                link[edge[i].v] = x;
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
    for(int i=1;i<=cx;++i)
    {
        memset(visited, false, sizeof(visited));
        if(dfs(i))
        {
            ++ ans;
        }
    }
    return ans;
}

int main()
{
    scanf("%d%d",&r,&c);
    memset(muddy, 0, sizeof(muddy));
    for(int i=1;i<=r;++i)
    {
        scanf("%s", muddy[i] + 1);
    }
    make();
    printf("%d\n", hungray());
    return 0;
}
