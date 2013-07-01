#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1005
#define MAXM 10005

int father[MAXN];
int vertexNumber,edgeNumber;
int ans, cnt;

struct Edge
{
    int u,v,w;
}edge[MAXM];

bool cmp(const Edge a, const Edge b)
{
    return a.w < b.w;
}

void init()
{
    for(int i=1;i<=vertexNumber;i++)
    {
        father[i] = i;
    }
}

int find(int x)
{
    if(x==father[x]) return x;
    return father[x]=find(father[x]);
}

void combine(int x, int y)
{
    x=find(x), y=find(y);
    father[x] = y;
}

void kruskal()
{
    init();
    sort(edge, edge+edgeNumber, cmp);
    for(int i=0;i<edgeNumber;i++)
    {
        if(find(edge[i].u) != find(edge[i].v))
        {
            combine(edge[i].u, edge[i].v);
            ans += edge[i].w;
            ++ cnt;
        }
    }
}

int main(int argc, char *argv[])
{
    while(~scanf("%d%d",&vertexNumber, &edgeNumber))
    {
        for(int i=0;i<edgeNumber;++i)
        {
            scanf("%d%d%d",&edge[i].u, &edge[i].v, &edge[i].w);
        }
        ans = 0;
        cnt = 0;
        kruskal();
        if(cnt == vertexNumber - 1)
        {
            printf("%d\n", ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
