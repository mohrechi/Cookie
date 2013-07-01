#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct Node
{
    __int64 p;
    int index;
    bool operator < (const Node &node) const
    {
        return p < node.p;
    }
}x[MAXN], y[MAXN];
__int64 l[MAXN], r[MAXN], u[MAXN], d[MAXN];

inline __int64 absolute(__int64 x)
{
    return x >= 0 ? x : -x;
}

inline __int64 min(__int64 x, __int64 y)
{
    return x < y ? x : y;
}

int main()
{
    int t, n, tx, ty;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &tx, &ty);
            x[i].p = tx - ty;
            y[i].p = tx + ty;
            x[i].index = i;
            y[i].index = i;
        }
        sort(x, x + n);
        sort(y, y + n);
        l[x[0].index] = 0;
        d[y[0].index] = 0;
        for(int i=1;i<n;++i)
        {
            l[x[i].index] = l[x[i-1].index] + absolute(x[i].p - x[i-1].p) * i;
            d[y[i].index] = d[y[i-1].index] + absolute(y[i].p - y[i-1].p) * i;
        }
        r[x[n-1].index] = 0;
        u[y[n-1].index] = 0;
        for(int i=n-2;i>=0;--i)
        {
            r[x[i].index] = r[x[i+1].index] + absolute(x[i].p - x[i+1].p) * (n - i - 1);
            u[y[i].index] = u[y[i+1].index] + absolute(y[i].p - y[i+1].p) * (n - i - 1);
        }
        __int64 ans = l[0] + r[0] + u[0] + d[0];
        for(int i=1;i<n;++i)
        {
            ans = min(ans, l[i] + r[i] + u[i] + d[i]);
        }
        printf("%I64d\n", ans>>1);
    }
    return 0;
}
