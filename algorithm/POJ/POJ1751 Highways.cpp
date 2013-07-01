#include <cstdio>
#include <algorithm>
using namespace std;
static const int MAXN = 800;
struct Point
{
    int x, y;
}point[MAXN];

struct Edge
{
    int u, v, w;
    bool operator < (const Edge &e) const
    {
        return w < e.w;
    }
}edge[MAXN * MAXN];
int edgeNumber;

int n,m;
int father[MAXN];

int dist(int i, int j)
{
    return (point[i].x - point[j].x) * (point[i].x - point[j].x) + (point[i].y - point[j].y) * (point[i].y - point[j].y);
}

int find(int x)
{
    if (x == father[x])
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

int main(int argc, char *argv[])
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d",&point[i].x, &point[i].y);
        father[i] = i;
    }
    scanf("%d",&m);
    int a,b,c=0;
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&a,&b);
        if(find(a) != find(b))
        {
            ++c;
            combine(a, b);
        }
    }
    if(c == n - 1)
    {
        return 0;
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            edge[edgeNumber].u = i;
            edge[edgeNumber].v = j;
            edge[edgeNumber].w = dist(i, j);
            ++edgeNumber;
        }
    }
    sort(edge, edge + edgeNumber);
    for(int i=0;i<edgeNumber && c != n-1;++i)
    {
        if(find(edge[i].u) != find(edge[i].v))
        {
            ++ c;
            combine(edge[i].u, edge[i].v);
            printf("%d %d\n", edge[i].u, edge[i].v);
        }
    }
    return 0;
}
