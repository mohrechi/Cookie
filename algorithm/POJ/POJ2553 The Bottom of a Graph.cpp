#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 5010;
const int MAXM = MAXN * MAXN;

struct Edge
{
    int v, next;
}edge[MAXM];
int edgeNumber, head[MAXN];
int dfn[MAXN], low[MAXN];
int n, m;
int stack[MAXN], top;
bool inStack[MAXN];
int timeStamp;
vector<int> component[MAXN];
int componentNumber;
int belong[MAXN];
vector<int> ans;

void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void dfs(int x)
{
    dfn[x] = low[x] = timeStamp ++;
    stack[top++] = x;
    inStack[x] = true;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(dfn[v] == -1)
        {
            dfs(v);
            if(low[x] > low[v])
            {
                low[x] = low[v];
            }
        }
        else if(inStack[v])
        {
            if(low[x] > dfn[v])
            {
                low[x] = dfn[v];
            }
        }
    }
    if(low[x] == dfn[x])
    {
        do
        {
            component[componentNumber].push_back(stack[-- top]);
            inStack[stack[top]] = false;
            belong[stack[top]] = componentNumber;
        }
        while(stack[top] != x);
        ++ componentNumber;
    }
}

void tarjan()
{
    memset(dfn, -1, sizeof(dfn));
    memset(stack, -1, sizeof(stack));
    memset(inStack, false, sizeof(inStack));
    top = 0;
    timeStamp = 0;
    componentNumber = 0;
    for(int i=0;i<n;++i)
    {
        component[i].clear();
    }
    for(int i=1;i<=n;++i)
    {
        if(dfn[i] == -1)
        {
            dfs(i);
        }
    }
    ans.clear();
    for(int i=0;i<componentNumber;++i)
    {
        bool valid = true;
        for(int j=0;j<component[i].size() && valid;++j)
        {
            int u = component[i][j];
            for(int k = head[u];k!=-1;k=edge[k].next)
            {
                int v = edge[k].v;
                if(belong[v] != belong[u])
                {
                    valid = false;
                    break;
                }
            }
        }
        if(valid)
        {
            for(int j=0;j<component[i].size();++j)
            {
                ans.push_back(component[i][j]);
            }
        }
    }
    sort(ans.begin(), ans.end());
}

int main()
{
    int u, v;
    while(scanf("%d", &n), n)
    {
        scanf("%d", &m);
        edgeNumber = 0;
        memset(head, -1, sizeof(head));
        for(int i=0;i<m;++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        tarjan();
        for(int i=0;i<ans.size();++i)
        {
            if(i)
            {
                printf(" ");
            }
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}
