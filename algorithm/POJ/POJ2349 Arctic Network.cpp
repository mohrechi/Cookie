#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
static const int MAXN = 501;
struct Point
{
    int x, y;
    inline void input()
    {
        scanf("%d%d", &x, &y);
    }
}position[MAXN];
double graph[MAXN][MAXN];
double ans;
int n, m;
bool visited[MAXN];
double dist[MAXN];
double da[MAXN];

inline double min(double x, double y)
{
    return x < y ? x : y;
}

inline double getDist(const Point &a, const Point &b)
{
    return sqrt((double)((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

void prim(int u1, int u2)
{
    memset(visited, false, sizeof(visited));
    visited[u1] = visited[u2] = true;
    double mi = 1e100;
    int choose;
    for(int i=0;i<n;++i)
    {
        dist[i] = min(graph[u1][i], graph[u2][i]);
        if(dist[i] < mi && !visited[i])
        {
            mi = dist[i];
            choose = i;
        }
    }
    da[1] = graph[u1][u2];
    for(int k=2;k<n;++k)
    {
        da[k] = dist[choose];
        visited[choose] = true;
        mi = 1e100;
        for(int i=0;i<n;++i)
        {
            dist[i] = min(dist[i], graph[choose][i]);
        }
        for(int i=0;i<n;++i)
        {
            if(mi > dist[i] && !visited[i])
            {
                mi = dist[i];
                choose = i;
            }
        }
    }
    sort(da + 1, da + n);
    ans = da[n - m];
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &m, &n);
        for(int i=0;i<n;++i)
        {
            position[i].input();
        }
        double mi = 1e100;
        int u1, u2;
        for(int i=0;i<n;++i)
        {
            graph[i][i] = 0.0;
            for(int j=i+1;j<n;++j)
            {
                graph[i][j] = graph[j][i] = getDist(position[i], position[j]);
                if(graph[i][j] < mi)
                {
                    mi = graph[i][j];
                    u1 = i, u2 = j;
                }
            }
        }
        if(n - m == 0)
        {
            ans = 0.0;
        }
        else if(n - m == 1)
        {
            ans = mi;
        }
        else
        {
            prim(u1, u2);
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
