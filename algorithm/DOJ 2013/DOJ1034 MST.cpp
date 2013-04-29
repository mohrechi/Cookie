#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int MAXM = 100005;

int n, m;
struct Edge
{
    int u, v, l, c;
    bool operator < (const Edge &edge) const
    {
        if (l == edge.l)
        {
            return c < edge.c;
        }
        return l < edge.l;
    }
} edge[MAXM];

int father[MAXN];

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        father[i] = i;
    }
}

int find(int x)
{
    if (father[x] == x)
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

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        init();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d%d%d", &edge[i].u, &edge[i].v, &edge[i].l, &edge[i].c);
        }
        sort(edge, edge + m);
        int lsum = 0, csum = 0;
        int num = 0;
        for (int i = 0; i < m; ++i)
        {
            if (find(edge[i].u) != find(edge[i].v))
            {
                combine(edge[i].u, edge[i].v);
                ++num;
                lsum += edge[i].l;
                csum += edge[i].c;
            }
        }
        if (num == n - 1)
        {
            printf("%d %d\n", lsum, csum);
        }
        else
        {
            printf("-1 -1\n");
        }
    }
    return 0;
}
