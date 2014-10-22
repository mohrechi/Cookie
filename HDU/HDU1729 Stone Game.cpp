#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int getSG(long long a, long long b)
{
    if (a == b)
    {
        return 0;
    }
    if (b + b * b >= a)
    {
        return a - b;
    }
    long long l = b, r = a, next = 0;
    while (l <= r)
    {
        long long m = (l + r) >> 1;
        if (m + m * m <= a)
        {
            next = max(next, m);
            l = m + 1;
        }
        else
        {
            r = m - 1;
        }
    }
    return getSG(next, b);
}

int main()
{
    int n, a, b, t = 0;
    while (scanf("%d", &n), n)
    {
        int ans = 0;
        while (n--)
        {
            scanf("%d%d", &a, &b);
            ans ^= getSG(a, b);
        }
        printf("Case %d:\n%s\n", ++t, ans ? "Yes" : "No");
    }
    return 0;
}
