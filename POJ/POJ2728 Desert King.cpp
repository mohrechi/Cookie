#include <cstdio>
#include <cstring>
#include <cmath>
static const int MAXN = 1001;
static const double INF = 1000000000;
static const double eps = 1e-3;

struct Village
{
    double x, y, h;
    void input()
    {
        scanf("%lf%lf%lf",&x,&y,&h);
    }
}v[MAXN];
int n,pre[MAXN];
bool visited[MAXN];
double dist[MAXN];
double g[MAXN][MAXN],c[MAXN][MAXN],d[MAXN][MAXN];

inline int dblcmp(double x)
{
    if(fabs(x) < eps)
    {
        return 0;
    }
    return x > 0 ? 1 : -1;
}

inline int square(int x)
{
    return x * x;
}

inline double cost(const Village &a, const Village &b)
{
    return fabs((double)(a.h - b.h));
}

inline double distance(const Village &a, const Village &b)
{
    return sqrt((double)(square(a.x - b.x) + square(a.y - b.y)));
}

inline void preCreateGraph()
{
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            c[i][j] = c[j][i] = cost(v[i], v[j]);
            d[i][j] = d[j][i] = distance(v[i], v[j]);
        }
    }
}

inline void createGraph(double expect)
{
    for(int i=1;i<=n;++i)
    {
        for(int j=i+1;j<=n;++j)
        {
            g[i][j] = g[j][i] = c[i][j] - expect * d[i][j];
        }
    }
}

inline double prim()
{
    double totalDist = 0.0;
    double totalCost = 0.0;
    memset(visited, false, sizeof(visited));
    visited[1] = true;
    for(int i=2;i<=n;++i)
    {
        dist[i] = g[1][i];
        pre[i] = 1;
    }
    int pos;
    for(int i=1;i<n;++i)
    {
        double min = INF;
        for(int j=2;j<=n;++j)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                pos = j;
            }
        }
        visited[pos] = true;
        totalDist += d[pre[pos]][pos];
        totalCost += c[pre[pos]][pos];
        for(int j=2;j<=n;++j)
        {
            if(!visited[j] && g[pos][j] < dist[j])
            {
                dist[j] = g[pos][j];
                pre[j] = pos;
            }
        }
    }
    return totalCost / totalDist;
}

int main()
{
    while(scanf("%d",&n),n)
    {
        for(int i=1;i<=n;++i)
        {
            v[i].input();
        }
        preCreateGraph();
        double expect = 100.0, real = 0.0;
        while(dblcmp(real - expect))
        {
            expect = real;
            createGraph(expect);
            real = prim();
        }
        printf("%.3lf\n", real);
    }
    return 0;
}
