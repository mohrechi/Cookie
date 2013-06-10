#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

double n, m;
int k;
struct Point
{
    double x, y;
    inline void input()
    {
        scanf("%lf%lf", &x, &y);
        x = x - 0.5;
        y = y - 0.5;
    }
} points[MAXN];

double dist(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct Edge
{
    int v, next;
} edge[MAXN * MAXN * 2];
int head[MAXN], edgeNum;

inline void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

bool visit[MAXN];

bool dfs(int u)
{
    if (!visit[u])
    {
        visit[u] = true;
        if (u == 1)
        {
            return true;
        }
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            if (dfs(edge[i].v))
            {
                return true;
            }
        }
    }
    return false;
}

bool judge(double len)
{
    clearEdge();
    for (int i = 0; i < k; ++i)
    {
        if (points[i].x < len + 0.5)
        {
            addEdge(0, i + 2);
        }
        if (n - points[i].x < len + 0.5)
        {
            addEdge(i + 2, 1);
        }
        for (int j = i + 1; j < k; ++j)
        {
            if (dist(points[i], points[j]) < len * 2)
            {
                addEdge(i + 2, j + 2);
                addEdge(j + 2, i + 2);
            }
        }
    }
    memset(visit, false, sizeof(visit));
    return !dfs(0);
}

int main()
{
    while (~scanf("%lf%lf%d", &n, &m, &k))
    {
        for (int i = 0; i < k; ++i)
        {
            points[i].input();
        }
        double ans = 0.0;
        double left = 0.0;
        double right = max(n, m);
        while (right - left > 0.001)
        {
            double mid = (left + right) * 0.5;
            if (judge(mid))
            {
                left = mid;
                ans = max(ans, mid);
            }
            else
            {
                right = mid;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
