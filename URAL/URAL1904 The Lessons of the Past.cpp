#include <cstdio>
#include <algorithm>
using namespace std;

struct Interval
{
    int u, v;
    inline int len() const
    {
        return v - u;
    }
} interval[2][1 << 12];

bool operator <(const Interval &a, const Interval &b)
{
    if (a.u == b.u)
    {
        return a.v > b.v;
    }
    return a.u < b.u;
}

int main()
{
    int k, a[20];
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &a[i]);
    }
    int n = 1;
    interval[0][0] = {0, 1};
    int cur = 0, next = 1;
    for (int i = k - 1; i >= 0; --i)
    {
        int m = 0;
        for (int j = 0; j < n; ++j)
        {
            int u = a[i] - interval[cur][j].v;
            int v = min(a[i], a[i] - interval[cur][j].u);
            if (u <= v)
            {
                interval[next][m++] = {u, v};
            }
            u = max(a[i], a[i] + interval[cur][j].u);
            v = a[i] + interval[cur][j].v;
            if (u <= v)
            {
                interval[next][m++] = {u, v};
            }
        }
        if (m == 0)
        {
            n = 0;
            break;
        }
        sort(interval[next], interval[next] + m);
        int u = interval[next][0].u;
        int v = interval[next][0].v;
        int k = 0;
        for (int j = 1; j < m; ++j)
        {
            if (interval[next][j].u > v)
            {
                interval[next][k++] = {u, v};
                u = interval[next][j].u;
                v = interval[next][j].v;
            }
            else
            {
                v = max(v, interval[next][j].v);
            }
        }
        interval[next][k++] = {u, v};
        n = k;
        cur ^= 1;
        next ^= 1;
    }
    printf("%d\n", n);
    for (int i = 0; i < n; ++i)
    {
        printf("%d %d\n", interval[cur][i].u, interval[cur][i].v);
    }
    return 0;
}
