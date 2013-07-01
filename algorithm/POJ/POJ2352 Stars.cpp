#include <cstdio>
#include <cstring>
const int MAXN = 15005;
const int MAXX = 32005;

int n, c[MAXX];
int level[MAXN];

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x)
{
    while(x < MAXX)
    {
        ++ c[x];
        x += lowbit(x);
    }
}

int query(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
    int x, y;
    while(~scanf("%d", &n))
    {
        memset(c, 0, sizeof(c));
        memset(level, 0, sizeof(level));
        for(int i=1;i<=n;++i)
        {
            scanf("%d%d", &x, &y);
            update(++x);
            ++ level[query(x)];
        }
        for(int i=1;i<=n;++i)
        {
            printf("%d\n", level[i]);
        }
    }
    return 0;
}
