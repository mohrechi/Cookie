#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int t, n, m, k;
struct Point
{
    int x, y;
    bool operator < (const Point &p) const
    {
        if(y == p.y)
        {
            return x > p.x;
        }
        return y > p.y;
    }
}point[MAXN * MAXN];
long long c[MAXN];

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x)
{
    while(x < MAXN)
    {
        ++ c[x];
        x += lowbit(x);
    }
}

long long query(int x)
{
    long long sum = 0;
    while(x > 0)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
    scanf("%d", &t);
    for(int j=1;j<=t;++j)
    {
        memset(c, 0, sizeof(c));
        scanf("%d%d%d", &n, &m, &k);
        for(int i=0;i<k;++i)
        {
            scanf("%d%d", &point[i].x, &point[i].y);
        }
        sort(point, point + k);
        long long ans = 0;
        for(int i=0;i<k;++i)
        {
            ans += query(point[i].x - 1);
            update(point[i].x);
        }
        printf("Test case %d: %lld\n", j, ans);
    }
    return 0;
}
