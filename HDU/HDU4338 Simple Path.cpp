#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 200010;
const int MAXM = 800010;

#ifndef ONLINE_JUDGE
    #define TEST_TARJAN
    #define TEST_CONTRACT
    #define TEST_LCA
#endif

struct Edge
{
    int v, next;
}edge[MAXM];
int edgeNumber, head[MAXN];
int n, m;

inline void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

int timeStamp;
int su[MAXM], sv[MAXM], top;
int dfn[MAXN], low[MAXN];
int componentNumber;
int inComponent[MAXN];
vector<int> component[MAXN];
bool isCut[MAXN];
int cut[MAXN], cutNumber;
int cutMap[MAXN];
int color[MAXN];

int dfsStack[MAXN * 6];
int dfsStackTop;

inline void dfsStackPush(const int &x)
{
    dfsStack[dfsStackTop++] = x;
}

inline void dfsStackPop()
{
    -- dfsStackTop;
}

inline int getDfsStackTop()
{
    return dfsStack[dfsStackTop - 1];
}

inline bool isDfsStackEmpty()
{
    return dfsStackTop == 0;
}

inline void clearDfsStack()
{
    dfsStackTop = 0;
}

void tarjanDfs(int u, int father, bool isRoot, int c)
{
    int childNumber = 0;
    int i;
tarjanDfsStart:
    color[u] = c;
    dfn[u] = low[u] = timeStamp ++;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        if(edge[i].v != father)
        {
            if(dfn[edge[i].v] == -1)
            {
                su[top] = u;
                sv[top] = edge[i].v;
                ++ top;
                dfsStackPush(i);
                dfsStackPush(u);
                dfsStackPush(father);
                dfsStackPush(isRoot);
                father = u;
                u = edge[i].v;
                isRoot = false;
                goto tarjanDfsStart;
tarjanDfsContinue:
                low[u] = min(low[u], low[edge[i].v]);
                if(isRoot)
                {
                    if(++childNumber >= 2)
                    {
                        isCut[u] = true;
                    }
                }
                else
                {
                    if(dfn[u] <= low[edge[i].v])
                    {
                        isCut[u] = true;
                    }
                }
                if(dfn[u] <= low[edge[i].v])
                {
                    int t;
                    do
                    {
                        t = su[--top];
                        component[componentNumber].push_back(sv[top]);
                    }while(t != u);
                    component[componentNumber].push_back(u);
                    ++ componentNumber;
                }
            }
            else
            {
                low[u] = min(low[u], dfn[edge[i].v]);
            }
        }
    }
    if(isRoot)
    {
        if(top > 2)
        {
            component[componentNumber].push_back(su[0]);
            for(int i=0;i<top;++i)
            {
                component[componentNumber].push_back(sv[i]);
            }
            ++ componentNumber;
        }
        top = 0;
    }
    if(!isDfsStackEmpty())
    {
        isRoot = getDfsStackTop();
        dfsStackPop();
        father = getDfsStackTop();
        dfsStackPop();
        u = getDfsStackTop();
        dfsStackPop();
        i = getDfsStackTop();
        dfsStackPop();
        goto tarjanDfsContinue;
    }
}

void tarjan()
{
    timeStamp = 0;
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    memset(isCut, false, sizeof(isCut));
    for(int i=0;i<n;++i)
    {
        component[i].clear();
    }
    top = componentNumber = cutNumber = 0;
    int colorNumber = 0;
    clearDfsStack();
    for(int i=0;i<n;++i)
    {
        if(dfn[i] == -1)
        {
            tarjanDfs(i, -1, true, colorNumber++);
        }
    }
    for(int i=0;i<n;++i)
    {
        if(isCut[i])
        {
            cutMap[i] = cutNumber;
            cut[cutNumber++] = i;
        }
    }
}

#ifdef TEST_TARJAN
void tarjanTest()
{
    printf("dfn: ");
    for(int i=0;i<n;++i)
    {
        printf("%d ", dfn[i]);
    }
    printf("\n");
    printf("low: ");
    for(int i=0;i<n;++i)
    {
        printf("%d ", low[i]);
    }
    printf("\n");
    printf("Cut Point: %d\n", cutNumber);
    for(int i=0;i<cutNumber;++i)
    {
        printf("%d ", cut[i]);
    }
    printf("\n");
    printf("Cut Point Map: %d\n");
    for(int i=0;i<n;++i)
    {
        if(isCut[i])
        {
            printf("%d %d\n", i, cutMap[i]);
        }
    }
    printf("\n");
    printf("Component Number: %d\n", componentNumber);
    for(int i=0;i<componentNumber;++i)
    {
        printf("%d: ", i);
        for(vector<int>::iterator it = component[i].begin();it!=component[i].end();++it)
        {
            printf("%d ", *it);
        }
        printf("\n");
    }
}
#endif

int pointNumber[MAXN];

void contract()
{
    clearEdge();
    memset(pointNumber, 0, sizeof(pointNumber));
    for(int i=0;i<componentNumber;++i)
    {
        for(vector<int>::iterator it = component[i].begin();it!=component[i].end();++it)
        {
            if(isCut[*it])
            {
                int v = componentNumber + cutMap[*it];
                addEdge(i, v);
                addEdge(v, i);
                pointNumber[v] = 1;
                inComponent[*it] = v;
            }
            else
            {
                ++ pointNumber[i];
                inComponent[*it] = i;
            }
        }
    }
}

#ifdef TEST_CONTRACT
void contractTest()
{
    printf("Point Number: \n");
    for(int i=0;i<componentNumber + cutNumber;++i)
    {
        printf("%d ", pointNumber[i]);
    }
    printf("\n");
    printf("Point Position Map: \n");
    for(int i=0;i<n;++i)
    {
        printf("%d ", inComponent[i]);
    }
    printf("\n");
    printf("Graph: \n");
    for(int i=0;i<componentNumber + cutNumber;++i)
    {
        printf("%d: ", i);
        for(int j=head[i];j!=-1;j=edge[j].next)
        {
            printf("%d ", edge[j].v);
        }
        printf("\n");
    }
}
#endif

int father[MAXN];
int depth[MAXN];
int num[MAXN];

void LCAdfs(int u, int f, int d, int s)
{
    int i;
LCAdfsStart:
    depth[u] = d;
    father[u] = f;
    if(u < componentNumber)
    {
        num[u] = s + pointNumber[u];
        for(i=head[u];i!=-1;i=edge[i].next)
        {
            if(edge[i].v != f)
            {
                ++ num[u];
            }
        }
    }
    else
    {
        num[u] = s;
    }
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        if(edge[i].v != f)
        {
            dfsStackPush(i);
            dfsStackPush(u);
            dfsStackPush(f);
            dfsStackPush(d);
            f = u;
            s = num[u];
            u = edge[i].v;
            d = d + 1;
            goto LCAdfsStart;
LCAdfsContinue:
            s;
        }
    }
    if(!isDfsStackEmpty())
    {
        d = getDfsStackTop();
        dfsStackPop();
        f = getDfsStackTop();
        dfsStackPop();
        u = getDfsStackTop();
        dfsStackPop();
        i = getDfsStackTop();
        dfsStackPop();
        goto LCAdfsContinue;
    }
}

void initLCA()
{
    memset(depth, -1, sizeof(depth));
    int nn = componentNumber + cutNumber;
    clearDfsStack();
    for(int i=0;i<nn;++i)
    {
        if(depth[i] == -1)
        {
            LCAdfs(i, -1, 0, 0);
        }
    }
}

int getLCA(int u, int v)
{
    while(depth[u] > depth[v])
    {
        u = father[u];
    }
    while(depth[v] > depth[u])
    {
        v = father[v];
    }
    if(u == v)
    {
        return u;
    }
    while(true)
    {
        if(father[u] == father[v])
        {
            return father[u];
        }
        u = father[u];
        v = father[v];
    }
    return 10086;
}

#ifdef TEST_LCA
void lcaTest()
{
    int nn = componentNumber + cutNumber;
    printf("Index: Depth Father Number\n");
    for(int i=0;i<nn;++i)
    {
        printf("%d: %d %d %d\n", i, depth[i], father[i], num[i]);
    }
}
#endif

int query(int x, int y)
{
    if(x == y)
    {
        return n - 1;
    }
    if(color[x] != color[y])
    {
        return n;
    }
    x = inComponent[x];
    y = inComponent[y];
    m = getLCA(x, y);
    int ans = num[x] + num[y] - num[m];
    if(father[m] != -1)
    {
        ans -= num[father[m]] - 1;
    }
    return n - ans;
}

int main()
{
    int caseNumber = 0;
    int u, v, q;
    while(~scanf("%d%d",&n,&m))
    {
        clearEdge();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d", &u, &v);
            if(u == v)
            {
                continue;
            }
            int j;
            for(j=head[u];j!=-1;j=edge[j].next)
            {
                if(edge[j].v == v)
                {
                    break;
                }
            }
            if(j != -1)
            {
                continue;
            }
            addEdge(u, v);
            addEdge(v, u);
        }
        tarjan();
        #ifdef TEST_TARJAN
        tarjanTest();
        #endif
        contract();
        #ifdef TEST_CONTRACT
        contractTest();
        #endif
        initLCA();
        #ifdef TEST_LCA
        lcaTest();
        #endif
        scanf("%d", &q);
        printf("Case #%d:\n", ++ caseNumber);
        while(q--)
        {
            scanf("%d%d", &u, &v);
            printf("%d\n", query(u, v));
        }
        printf("\n");
    }
    return 0;
}
