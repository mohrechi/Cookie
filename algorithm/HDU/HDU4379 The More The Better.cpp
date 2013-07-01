#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    __int64 n, l, a, b, mod;
    while(~scanf("%I64d%I64d%I64d%I64d%I64d",&n,&l,&a,&b,&mod))
    {
        a %= mod;
        __int64 cur = (a + b) % mod;
        __int64 mid = l >> 1;
        __int64 high = 1e18, low = 0;
        __int64 ans = 0;
        for(int i=0;i<n;++i)
        {
            if(cur <= mid)
            {
                low = max(low, cur);
                ++ ans;
            }
            else
            {
                high = min(high, cur);
            }
            cur += a;
            if(cur >= mod)
            {
                cur -= mod;
            }
        }
        if(low + high <= l)
        {
            ++ ans;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
