#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXK = 20;
const int MOD1 = 97;
const int MOD2 = 3761599;
const int MOD = MOD1 * MOD2;

int n, m, k;
int a[MAXK];
__int64 p1[MOD1], p2[MOD2];
__int64 c1, c2;

__int64 pow_mod(__int64 x, __int64 y, __int64 mod)
{
    __int64 res = 1;
    while(y)
    {
        if(y & 1)
        {
            res = (res * x) % mod;
        }
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

__int64 cm(__int64 n, __int64 m, __int64 mod, __int64 p[])
{
    if(n < m)
    {
        return 0;
    }
    __int64 res = (p[n] * pow_mod(p[m], mod - 2, mod)) % mod;
    return (res * pow_mod(p[n - m], mod - 2, mod)) % mod;
}

__int64 lucas(__int64 n, __int64 m, __int64 mod, __int64 p[])
{
    __int64 res = 1;
    while(n && m && res)
    {
        res = (res * cm(n % mod, m % mod, mod, p)) % mod;
        n /= mod;
        m /= mod;
    }
    return res;
}

void init()
{
    p1[0] = p2[0] = 1;
    for(int i=1;i<MOD1;++i)
    {
        p1[i] = (p1[i-1] * i) % MOD1;
    }
    for(int i=1;i<MOD2;++i)
    {
        p2[i] = (p2[i-1] * i) % MOD2;
    }
    c1 = MOD2 * pow_mod(MOD2, MOD1 - 2, MOD1);
    c2 = MOD1 * pow_mod(MOD1, MOD2 - 2, MOD2);
}

int main()
{
    init();
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d%d%d", &n, &m, &k);
        for(int i=0;i<k;++i)
        {
            scanf("%d", &a[i]);
        }
        a[k] = m;
        __int64 ans = 1;
        for(int i=0;i<k;++i)
        {
            __int64 m1 = lucas(a[i+1] - a[i] + n - 1, a[i+1] - a[i], MOD1, p1);
            __int64 m2 = lucas(a[i+1] - a[i] + n - 1, a[i+1] - a[i], MOD2, p2);
            __int64 mm = (m1 * c1 + m2 * c2) % MOD;
            ans = (ans * mm) % MOD;
        }
        printf("Case #%d: %I64d\n", cas, ans);
    }
    return 0;
}
