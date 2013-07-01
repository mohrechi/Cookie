#include <cstdio>

int main(int argc, char *argv[])
{
    long long n,p,a,r;
    while(~scanf("%lld",&n))
    {
        r = n;
        for(long long i=2;i*i<=n;++i)
        {
            if(n%i == 0)
            {
                p=i;
                a=0;
                while(n%p == 0)
                {
                    ++a;
                    n/=p;
                }
                r+=r*a*(p-1)/p;
            }
        }
        if(n!=1)
        {
            r=r*(2*n-1)/n;
        }
        printf("%lld\n", r);
    }
    return 0;
}
