#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
static const int MAXN = 5005;
struct Edge
{
    int v, next;
}edge[MAXN*MAXN*2];
int edgeNumber, n, time;
int head[MAXN], dfn[MAXN], low[MAXN];
bool inStack[MAXN];
int stack[MAXN], top, type, belong[MAXN];
int ans[MAXN], ansNumber;

void init()
{
    edgeNumber = type = time = top = 0;
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
    memset(belong, 0, sizeof(belong));
    memset(inStack, false, sizeof(inStack));
}

void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void input()
{
    int k, j;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&j);
            addEdge(i, j + n);
        }
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&j);
        addEdge(j + n, i);
    }
}

void dfs(int x)
{
    dfn[x] = low[x] = ++ time;
    inStack[x] = true;
    stack[top++] = x;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        if(-1 == dfn[edge[i].v])
        {
            dfs(edge[i].v);
            if(low[edge[i].v] < low[x])
            {
                low[x] = low[edge[i].v];
            }
        }
        else if(inStack[edge[i].v] && dfn[edge[i].v] < low[x])
        {
            low[x] = dfn[edge[i].v];
        }
    }
    if(dfn[x] == low[x])
    {
        ++type;
        int i;
        do
        {
            i = stack[--top];
            inStack[i] = false;
            belong[i] = type;
        }while(i!=x);
    }
}

void tarjan()
{
    for(int i=1;i<=n;++i)
    {
        if(-1 == dfn[i])
        {
            dfs(i);
        }
    }
}

void output()
{
    for(int i=1;i<=n;++i)
    {
        ansNumber = 0;
        for(int j=head[i];j!=-1;j=edge[j].next)
        {
            if(belong[edge[j].v] == belong[i])
            {
                ans[ansNumber++] = edge[j].v - n;
            }
        }
        sort(ans, ans + ansNumber);
        printf("%d", ansNumber);
        for(int j=0;j<ansNumber;++j)
        {
            printf(" %d", ans[j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    while(~scanf("%d",&n))
    {
        init();
        input();
        tarjan();
        output();
    }
    return 0;
}
