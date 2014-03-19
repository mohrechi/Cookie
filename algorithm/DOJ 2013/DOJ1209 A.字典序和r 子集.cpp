#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000000 + 10;
const int MOD = 1e9 + 7;

int n, r, a;
bool visit[MAXN];
long long fact[MAXN];

void init()
{
    fact[0] = 1;
    for (int i = 1; i < MAXN; ++i)
    {
        fact[i] = fact[i - 1] * i % MOD;
    }
}

long long power(long long x, long long y)
{
    if (0 == y)
    {
        return 1;
    }
    long long t = power(x, y >> 1);
    if (y & 1)
    {
        return t * t % MOD * x % MOD;
    }
    return t * t % MOD;
}

long long inverse(long long x)
{
    return power(x, MOD - 2);
}

long long c(long long n, long long m)
{
    if (m > n)
    {
        return 0;
    }
    return fact[n] * inverse(fact[m]) % MOD * inverse(fact[n - m]) % MOD;
}

int main()
{
    init();
    while (~scanf("%d%d", &n, &r))
    {
        memset(visit, false, sizeof(visit));
        for (int i = 1; i <= r; ++i)
        {
            scanf("%d", &a);
            visit[a] = true;
        }
        long long ans = 0;
        --r;
        for (int i = 1; i <= n && r >= 0; ++i)
        {
            if (visit[i])
            {
                --r;
            }
            else
            {
                ans = (ans + c(n - i, r)) % MOD;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
