#include <cstdio>
#include <cstring>
static const int MAXN = 40005;
static const int MAXM = 40005;
static const int MAXK = 40005;

struct Edge
{
    int v, w, next;
}edge[MAXM*2], edgeAnother[MAXK*2];
int edgeNumber, edgeNumberAnother;
int father[MAXN], head[MAXN], headAnother[MAXK];
int ancestor[MAXN], dist[MAXN];
int n, m, k, question[MAXN][2];
bool visited[MAXN], solved[MAXN];

void init()
{
    edgeNumber          = 0;
    edgeNumberAnother   = 0;
    for(int i=1;i<=n;++i)
    {
        father[i]       = i;
        head[i]         = -1;
        headAnother[i]   = -1;
        visited[i]      = false;
        solved[i]       = false;
    }
}

inline void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v      = v;
    edge[edgeNumber].w      = w;
    edge[edgeNumber].next   = head[u];
    head[u]                 = edgeNumber++;
}

inline void addEdgeAnother(int u, int v)
{
    edgeAnother[edgeNumberAnother].v        = v;
    edgeAnother[edgeNumberAnother].next     = headAnother[u];
    headAnother[u]                          = edgeNumberAnother++;
}

void input()
{
    int x, y, d;
    char s[5];
    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<m;++i)
    {
        scanf("%d%d%d%s",&x,&y,&d,s);
        addEdge(x, y, d);
        addEdge(y, x, d);
    }
    scanf("%d",&k);
    for(int i=0;i<k;++i)
    {
        scanf("%d%d",&question[i][0], &question[i][1]);
        addEdgeAnother(question[i][0], question[i][1]);
        addEdgeAnother(question[i][1], question[i][0]);
    }
}

int find(int x)
{
    if(x == father[x])
    {
        return x;
    }
    return father[x] = find(father[x]);
}

inline void combine(int x, int y)
{
    father[find(x)] = find(y);
}

void solve(int x, int d)
{
    visited[x]  = true;
    dist[x]     = d;
    ancestor[x] = x;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if(!visited[edge[i].v])
        {
            solve(edge[i].v, d + edge[i].w);
            combine(x, edge[i].v);
            ancestor[find(x)] = x;
        }
    }
    solved[x]   = true;
    for(int i=headAnother[x];i!=-1;i=edgeAnother[i].next)
    {
        if(solved[edgeAnother[i].v])
        {
            int w = dist[x] + dist[edgeAnother[i].v] - 2 * dist[ancestor[find(edgeAnother[i].v)]];
            edgeAnother[i].w = w;
            for(int j=headAnother[edgeAnother[i].v];j!=-1;j=edgeAnother[j].next)
            {
                if(edgeAnother[j].v == x)
                {
                    edgeAnother[j].w = w;
                    break;
                }
            }
        }
    }
}

void output()
{
    for(int i=0;i<k;++i)
    {
        for(int j=headAnother[question[i][0]];j!=-1;j=edgeAnother[j].next)
        {
            if(edgeAnother[j].v == question[i][1])
            {
                printf("%d\n", edgeAnother[j].w);
                break;
            }
        }
    }
}

void debug()
{
    printf("Connection Edge: \n");
    for(int i=1;i<=n;++i)
    {
        printf("\t%d: ", i);
        for(int j=head[i];j!=-1;j=edge[j].next)
        {
            printf("%d ", edge[j].v);
        }
        printf("\n");
    }
    printf("Question Edge: \n");
    for(int i=1;i<=n;++i)
    {
        printf("\t%d: ", i);
        for(int j=headAnother[i];j!=-1;j=edgeAnother[j].next)
        {
            printf("%d(%d) ", edgeAnother[j].v, edgeAnother[j].w);
        }
        printf("\n");
    }
    printf("Distance: \n\t");
    for(int i=1;i<=n;++i)
    {
        printf("%d ", dist[i]);
    }
    printf("\nAncestor: \n\t");
    for(int i=1;i<=n;++i)
    {
        printf("%d ", ancestor[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[])
{
    input();
    solve(1, 0);
    //debug();
    output();
    return 0;
}
