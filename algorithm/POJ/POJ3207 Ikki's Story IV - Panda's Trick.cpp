#include <iostream>
#include <cmath>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MAXN 1005
#define MAXM 1000005

int stack[MAXN], top, index;
bool inStack[MAXN];
int dfn[MAXN], low[MAXN];
int componentNumber;
int inComponent[MAXN];
int component[MAXN][MAXN];

struct Edge
{
    int u,v,next;
}edge[MAXM];
int edgeNumber, head[MAXN];

void addEdge(int u, int v)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void tarjan(int x)
{
    int t;
    dfn[x] = low[x] = index ++;
    inStack[x] = true;
    stack[top++] = x;
    for(int e=head[x];e!=-1;e=edge[e].next)
    {
        t = edge[e].v;
        if(dfn[t] == -1)
        {
            tarjan(t);
            low[x] = min(low[x], low[t]);
        }
        else if(inStack[t])
        {
            low[x] = min(low[x], dfn[t]);
        }
    }
    if(dfn[x] == low[x])
    {
        do
        {
            t = stack[--top];
            inStack[t] = false;
            component[componentNumber][0] ++;
            component[componentNumber][component[componentNumber][0]] = t;
            inComponent[t] = componentNumber;
        }
        while(t!=x);
        componentNumber ++;
    }
}

void solveComponent(int n)
{
    memset(inStack, false, sizeof(inStack));
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    memset(component, 0, sizeof(component));
    top = 0;
    index = 0;
    componentNumber = 0;
    for(int i=0;i<n;i++)
    {
        if(dfn[i] == -1)
        {
            tarjan(i);
        }
    }
}

int n,m;
int origin[MAXN][2];

void initEdge()
{
    scanf("%d%d",&n,&m);
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&origin[i][0],&origin[i][1]);
        if(origin[i][0] > origin[i][1])
        {
            origin[i][0] ^= origin[i][1];
            origin[i][1] ^= origin[i][0];
            origin[i][0] ^= origin[i][1];
        }
    }
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if((origin[i][0] < origin[j][0] &&
                origin[i][1] > origin[j][0] &&
                origin[i][1] < origin[j][1]) ||
                (origin[i][1] > origin[j][1] &&
                origin[i][0] > origin[j][0] &&
                origin[i][0] < origin[j][1]))
                {
                    addEdge(i, j+m);
                    addEdge(i+m, j);
                    addEdge(j, i+m);
                    addEdge(j+m, i);
                }
        }
    }
}

void judge()
{
    bool flag = true;
    for(int i=0;i<m;i++)
    {
        if(inComponent[i] == inComponent[i+m])
        {
            flag = false;
            break;
        }
    }
    if(flag)
    {
        printf("panda is telling the truth...\n");
    }
    else
    {
        printf("the evil panda is lying again\n");
    }
}

int main(int argc, char *argv[])
{
    initEdge();
    solveComponent(m*2);
    judge();
    return 0;
}
