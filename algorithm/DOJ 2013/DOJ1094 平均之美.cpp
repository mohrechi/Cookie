#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int MAXM = 100005;

int n, m;
struct Edge
{
    int u, v, w;
    inline void input()
    {
        scanf("%d%d%d", &u, &v, &w);
    }
    bool operator <(const Edge &edge) const
    {
        return w < edge.w;
    }
} edge[MAXM];

int father[MAXN];
bool used[MAXM];

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        father[i] = i;
    }
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
    father[find(x)] = find(y);
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < m; ++i)
        {
            edge[i].input();
        }
        sort(edge, edge + m);
        memset(used, false, sizeof(used));
        int num = 1;
        double total = 0.0;
        init();
        for (int i = 0; i < m; ++i)
        {
            if (find(edge[i].u) != find(edge[i].v))
            {
                combine(edge[i].u, edge[i].v);
                total += edge[i].w;
                ++num;
                used[i] = true;
            }
        }
        if (num == n)
        {
            -- num;
            for (int i = 0; i < m; ++i)
            {
                if (!used[i])
                {
                    if ((total + edge[i].w) / (num + 1) < total / num)
                    {
                        total += edge[i].w;
                        ++num;
                    }
                }
            }
            printf("%.2lf\n", total / num);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
