#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50 + 5;

__int64 top[MAXN];
__int64 mid[MAXN][MAXN];

__int64 getTop(int);
__int64 getMid(int, int);

__int64 getTop(int k)
{
    if (-1 != top[k])
    {
        return top[k];
    }
    if (0 == k)
    {
        return top[k] = 0;
    }
    return top[k] = getMid(1, k -1) + 1;
}

__int64 getMid(int m, int k)
{
    if (-1 != mid[m][k])
    {
        return mid[m][k];
    }
    if (0 == m)
    {
        return mid[m][k] = getTop(k);
    }
    if (0 == k)
    {
        return mid[m][k] = 0;
    }
    return mid[m][k] = getTop(m) + getMid(m + 1, k - 1) + 1;
}

int n, a[MAXN];
char s[MAXN];

int main()
{
    memset(top, -1, sizeof(top));
    memset(mid, -1, sizeof(mid));
    while (~scanf("%d%s", &n, s))
    {
        a[n] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if ('B' == s[i])
            {
                a[i] = a[i + 1] + 1;
                a[i + 1] = 0;
            }
            else
            {
                a[i] = 0;
            }
        }
        __int64 ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (a[i])
            {
                if (i)
                {
                    ans += getMid(i, a[i]);
                }
                else
                {
                    ans += getTop(a[i]);
                }
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
