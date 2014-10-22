#include <cstdio>
#include <cstring>

int main()
{
    long long n, t;
    scanf("%lld", &t);
    while(t--)
    {
        scanf("%lld", &n);
        int cnt = 0;
        for(long long i=1;i*i<=n;i+=2)
        {
            for(long long j=0;((i*i)<<j)<=n;++j)
            {
                ++ cnt;
            }
        }
        printf("%d\n", cnt % 2);
    }
    return 0;
}
