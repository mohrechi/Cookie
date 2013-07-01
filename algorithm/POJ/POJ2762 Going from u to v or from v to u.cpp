#include <iostream>
#include <cmath>
#include <stdio.h>
#include <memory.h>
using namespace std;
#define MAXN 1005

int stack[MAXN], top, index;
bool inStack[MAXN];
int dfn[MAXN], low[MAXN];
int componentNumber;
int inComponent[MAXN];
int component[MAXN][MAXN];
int edge[MAXN][MAXN];

void tarjan(int x)
{
    int t;
    dfn[x] = low[x] = index ++;
    inStack[x] = true;
    stack[top++] = x;
    for(int e=1;e<=edge[x][0];e++)
    {
        t = edge[x][e];
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
    componentNumber = 0;
    index = 0;
    for(int i=0;i<n;i++)
    {
        if(dfn[i] == -1)
        {
            tarjan(i);
        }
    }
}

bool graph[MAXN][MAXN];
int in[MAXN];

void reduction(int n)
{
    memset(graph, false, sizeof(graph));
    memset(in, 0, sizeof(in));
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=edge[i][0];j++)
        {
            graph[inComponent[i]][inComponent[edge[i][j]]] = true;
        }
    }
    for(int i=0;i<componentNumber;i++)
    {
        graph[i][i] = false;
        for(int j=0;j<componentNumber;j++)
        {
            if(graph[i][j])
            {
                in[j] ++;
            }
        }
    }
}

bool topological(int n)
{
    int count;
    int temp = n;
    int p;
    while(temp--)
    {
        count = 0;
        for(int i=0;i<n;i++)
        {
            if(!in[i])
            {
                count ++;
                p = i;
            }
        }
        if(count!=1)
        {
            return false;
        }
        for(int i=0;i<n;i++)
        {
            if(graph[p][i])
            {
                in[i] --;
            }
        }
        in[p] --;
    }
    return true;
}

int main(int argc, char *argv[])
{
    int t,n,m,a,b;
    scanf("%d",&t);
    while(t--)
    {
        memset(edge, 0, sizeof(edge));
        scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            a--, b--;
            edge[a][0] ++;
            edge[a][edge[a][0]] = b;
        }
        solveComponent(n);
        reduction(n);
        if(topological(componentNumber))
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
