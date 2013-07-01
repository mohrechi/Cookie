#include <cmath>
#include <cstdio>
#include <cstdlib>

int getDigit(long long x)
{
    int s = 0;
    while(x > 0)
    {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int main(int argc, char *argv[])
{
    long long a, b, t, s;
    while(~scanf("%lld%lld",&a,&b))
    {
        int cnt = 0;
        for(long long i=a;i<=b;++i)
        {
            bool flag = true;
            for(long long j=1;j<=81;++j)
            {
                if(getDigit(i*j) == j)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                ++cnt;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
