#include <cstdio>
#include <cstring>

void test(__int64 a, __int64 b, __int64 n)
{
    __int64 cnt = 0;
    for(__int64 i=1;i<=n;++i)
    {
        __int64 temp = b + a * i;
        for(__int64 j=0;j<64;++j)
        {
            if(temp & (1LL << j))
            {
                ++ cnt;
            }
        }
    }
    printf("Test %I64d\n", cnt);
}

int main()
{
    int t;
    __int64 a, b, n;
    scanf("%d", &t);
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%I64d%I64d%I64d",&a,&b,&n);
        __int64 cnt = 0;
        __int64 max = b + a * n;
        for(__int64 i=0;i<64;++i)
        {
            __int64 m = 1LL << i;
            if(m > max)
            {
                break;
            }
            m <<= 1;
            __int64 cur = a + b;
            __int64 mm = m >> 1;
            __int64 j = 0;
            while(j<m && j<n)
            {
                __int64 upper = cur + (mm - (cur % mm)) - 1LL;
                __int64 step = (upper - cur) / a + 1LL;
                if(j + step >= n)
                {
                    step = n - j;
                }
                if(j + step >= m)
                {
                    step = m - j;
                }
                if(cur & (1LL<<i))
                {
                    cnt += step * (n / m);
                    if(j + step < (n % m))
                    {
                        cnt += step;
                    }
                    else if(j < (n % m))
                    {
                        cnt += (n % m) - j;
                    }
                }
                cur += a * step;
                j += step;
            }
        }
        printf("Case #%d: %I64d\n", cas, cnt);
        //test(a, b, n);
    }
    return 0;
}
