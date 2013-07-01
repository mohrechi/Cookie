#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
static const int MAXN = 101;
static const double eps = 1e-8;

struct Sphere
{
    double x, y, z, r;
}sphere[MAXN];

struct Edge
{
    int u, v;
    double w;
    bool operator < (const Edge &edge) const
    {
        return w < edge.w;
    }
}edge[MAXN*MAXN/2];

int n, edgeNumber, father[MAXN];
double ans;

inline int dblcmp(double x)
{
    if(fabs(x)<eps)
    {
        return 0;
    }
    return x>0?1:-1;
}

inline bool less(double x, double y)
{
    return dblcmp(x - y) < 0;
}

inline double square(double x)
{
    return x * x;
}

inline double dist(const Sphere &a, const Sphere &b)
{
    return sqrt(square(a.x - b.x) + square(a.y - b.y) + square(a.z - b.z));
}

inline void addEdge(int u, int v, double w)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    ++edgeNumber;
}

inline int find(int x)
{
    if(x == father[x])
    {
        return x;
    }
    return father[x] = find(father[x]);
}

inline void combine(int x, int y)
{
    x = find(x);
    y = find(y);
    father[x] = y;
}

bool input()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%lf%lf%lf%lf", &sphere[i].x,&sphere[i].y,&sphere[i].z,&sphere[i].r);
    }
    return n!=0;
}

void init()
{
    double len;
    edgeNumber = 0;
    for(int i=0;i<n;++i)
    {
        father[i] = i;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            len = dist(sphere[i], sphere[j]);
            if(less(sphere[i].r + sphere[j].r, len))
            {
                addEdge(i, j, len - sphere[i].r - sphere[j].r);
            }
            else
            {
                combine(i, j);
            }
        }
    }
    ans = 0.0;
}

void solve()
{
    sort(edge, edge + edgeNumber);
    for(int i=0;i<edgeNumber;++i)
    {
        if(find(edge[i].u) != find(edge[i].v))
        {
            ans += edge[i].w;
            combine(edge[i].u, edge[i].v);
        }
    }
    printf("%.3lf\n", ans);
}

int main(int argc, char *argv[])
{
    while(input())
    {
        init();
        solve();
    }
    return 0;
}
