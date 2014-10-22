#include <cstdio>
#include <cmath>

long long aa[4];
long long ak[4];
int an;

int main()
{
    long long n;
    while(~scanf("%lld",&n))
    {
        an = 0;
        long long mk = (long long)pow(n * 3.0, 1.0/3) - 1;
        for(long long k=mk;k>=0;--k)
        {
            long long a = (long long)((-k+sqrt(k*k-2.0*k*(2*k+1)/3+4.0*n/(k+1)))/2);
            if((k+1)*(6*a*a+6*a*k+(2*k+1)*k) == n*6)
            {
                aa[an] = a;
                ak[an++] = k+1;
            }
        }
        printf("%d\n", an);
        for(int i=0;i<an;++i)
        {
            printf("%lld", ak[i]);
            for(int j=0;j<ak[i];++j)
            {
                printf(" %lld",aa[i]+j);
            }
            printf("\n");
        }
    }
    return 0;
}
