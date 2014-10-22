#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;
const double EPS = 1e-4;

struct Point
{
    int x, y, z;
    inline int input()
    {
        scanf("%d%d%d", &x, &y, &z);
    }
    inline double dist()
    {
        return sqrt(x * x + y * y + z * z);
    }
} red[MAXN], blue[MAXN];

inline Point operator -(const Point &a, const Point &b)
{
    Point c;
    c.x = a.x - b.x;
    c.y = a.y - b.y;
    c.z = a.z - b.z;
    return c;
}

double dist(const Point &a, const Point &b)
{
    return (a - b).dist();
}

int n;

struct Edge
{
    int v, next;
} edge[MAXN * MAXN * 4];
int head[MAXN * 2], edgeNum;

inline void addEdge(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

void build(double r)
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (dist(red[i], red[j]) < r * 2.0)
            {
                addEdge(i, j + n);
                addEdge(j, i + n);
            }
            if (dist(red[i], blue[j]) < r * 2.0)
            {
                addEdge(i, j);
                addEdge(j + n, i + n);
            }
            if (dist(blue[i], red[j]) < r * 2.0)
            {
                addEdge(i + n, j + n);
                addEdge(j, i);
            }
            if (dist(blue[i], blue[j]) < r * 2.0)
            {
                addEdge(i + n, j);
                addEdge(j + n, i);
            }
        }
    }
}

int stack[MAXN * 2], top, timeStamp;
bool inStack[MAXN * 2];
int dfn[MAXN * 2], low[MAXN * 2];
int belong[MAXN * 2], belongNum;

void tarjan(int u)
{
    dfn[u] = low[u] = timeStamp++;
    inStack[u] = true;
    stack[top++] = u;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (dfn[v] == -1)
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (inStack[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        int t;
        do
        {
            t = stack[--top];
            inStack[t] = false;
            belong[t] = belongNum;
        }
        while (t != u);
        ++belongNum;
    }
}

bool judge()
{
    top = timeStamp = belongNum = 0;
    memset(inStack, false, sizeof(inStack));
    memset(dfn, -1, sizeof(dfn));
    memset(low, -1, sizeof(low));
    for (int i = 0; i < n; ++i)
    {
        if (dfn[i] == -1)
        {
            tarjan(i);
        }
        if (dfn[i + n] == -1)
        {
            tarjan(i + n);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (belong[i] == belong[i + n])
        {
            return false;
        }
    }
    return true;
}

char ans[100];

int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            red[i].input();
            blue[i].input();
        }
        double left = 0.0, right = 20000.0;
        while (right - left > EPS)
        {
            double mid = (left + right) * 0.5;
            //printf("%lf %lf : %lf\n", left, right, mid);
            build(mid);
            if (judge())
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        sprintf(ans, "%.4lf", (left + right) * 0.5);
        ans[strlen(ans) - 1] = 0;
        printf("%s\n", ans);
    }
    return 0;
}
