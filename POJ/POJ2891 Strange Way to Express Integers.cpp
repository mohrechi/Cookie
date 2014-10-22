#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long ex_gcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    long long g = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return g;
}

bool reduce(long long &m1, long long &a1, long long m2, long long a2)
{
    long long x, y;
    long long c = a2 - a1;
    long long g = ex_gcd(m1, m2, x, y);
    if (c % g)
    {
        return false;
    }
    long long x0 = x * (c / g);
    m2 /= g;
    x0 = (x0 % m2 + m2) % m2;
    a1 = a1 + x0 * m1;
    m1 *= m2;
    return true;
}

int main()
{
    int k;
    long long a1, r1, a2, r2;
    while (~scanf("%d", &k))
    {
        bool flag = true;
        scanf("%lld%lld", &a1, &r1);
        for (int i = 1; i < k; ++i)
        {
            scanf("%lld%lld", &a2, &r2);
            if (!flag)
            {
                continue;
            }
            flag &= reduce(a1, r1, a2, r2);
        }
        if (flag)
        {
            printf("%lld\n", r1);
        }
        else
        {
            puts("-1");
        }
    }
    return 0;
}
