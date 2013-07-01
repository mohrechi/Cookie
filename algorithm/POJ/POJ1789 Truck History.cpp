#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
static const int MAXN = 2005;
char type[MAXN][8];
struct Edge
{
    int u,v,w;
    bool operator < (const Edge &e) const
    {
        return w < e.w;
    }
}edge[MAXN*MAXN/2];
int father[MAXN];
int n, edgeNumber;

int find(int x)
{
    if(x == father[x])
    {
        return x;
    }
    return father[x] = find(father[x]);
}

void combine(int x, int y)
{
    x = find(x);
    y = find(y);
    father[x] = y;
}

void input()
{
    for(int i=0;i<n;++i)
    {
        father[i] = i;
        scanf("%s", type[i]);
    }
    edgeNumber = 0;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            edge[edgeNumber].u = i;
            edge[edgeNumber].v = j;
            edge[edgeNumber].w = 0;
            for(int k=0;k<7;++k)
            {
                if(type[i][k] != type[j][k])
                {
                    ++edge[edgeNumber].w;
                }
            }
            ++ edgeNumber;
        }
    }
    sort(edge, edge + edgeNumber);
}

void solve()
{
    int answer = 0;
    for(int i=0;i<edgeNumber;++i)
    {
        if(find(edge[i].u) != find(edge[i].v))
        {
            answer += edge[i].w;
            combine(edge[i].u, edge[i].v);
        }
    }
    printf("The highest possible quality is 1/%d.\n", answer);
}

int main(int argc, char *argv[])
{
    while(scanf("%d",&n),n)
    {
        input();
        solve();
    }
    return 0;
}
