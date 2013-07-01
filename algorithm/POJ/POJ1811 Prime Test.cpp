#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
int factor[100], fac_top = -1;

long long gcd(long long small,long long big)
{
    while(small)
    {
        small ^= big;
        big ^= small;
        small ^= big;
        small%=big;
    }
    return (long long)fabs((double)big);
}

long long muti_mod(long long a,long long b,long long n)
{
    long long exp = a%n, res = 0;
    while(b)
    {
        if(b&1)
        {
            res += exp;
            if(res>n) res -= n;
        }
        exp <<= 1;
        if(exp>n) exp -= n;
        b>>=1;
    }
    return res;
}

long long mod_exp(long long a,long long p,long long m)
{
    long long exp=a%m, res=1;
    while(p>1)
    {
        if(p&1)
            res=muti_mod(res,exp,m);
        exp = muti_mod(exp,exp,m);
        p>>=1;
    }
    return muti_mod(res,exp,m);
}

bool miller_rabin(long long n, int times)
{
    if(n==2)return true;
    if(n<2||!(n&1))return false;
    long long a, u=n-1, x, y;
    int t=0;
    while(u%2==0)
    {
        t++;
        u/=2;
    }
    srand(time(0));
    for(int i=0;i<times;i++)
    {
        a = rand() % (n-1) + 1;
        x = mod_exp(a, u, n);
        for(int j=0;j<t;j++)
        {
            y = muti_mod(x, x, n);
            if(y == 1 && x != 1 && x != n-1)
                return false;
            x = y;
        }
        if(y!=1) return false;
    }
    return true;
}

long long pollard_rho(long long n,int c)
{
    long long x,y,d,i = 1,k = 2;
    srand(time(0));
    x = rand()%(n-1)+1;
    y = x;
    while(true)
    {
        i++;
        x = (muti_mod(x,x,n) + c) % n;
        d = gcd(y-x, n);
        if(1 < d && d < n)return d;
        if( y == x) return n;
        if(i == k)
        {
            y = x;
            k <<= 1;
        }
    }
}

void findFactor(long long n,int k)
{
    if(n==1)return;
    if(miller_rabin(n, 8))
    {
        factor[++fac_top] = n;
        return;
    }
    long long p = n;
    while(p >= n)
        p = pollard_rho(p,k--);
    findFactor(p,k);
    findFactor(n/p,k);
}

int main()
{
    long long cs,n,min;
    scanf("%lld", &cs);
    while(cs--)
    {
        scanf("%lld", &n);
        fac_top = min = -1;
        if(miller_rabin(n, 8))
            printf("Prime\n");
        else
        {
            findFactor(n,107);
            for(int i=0;i<=fac_top;i++)
            {
                if(min<0||factor[i]<min)
                    min = factor[i];
            }
            printf("%lld\n", min);
        }
    }

    return 0;
}
