#include <cstdio>
#include <cstring>
static const int MAXN = 1000010;
long long a[MAXN];
bool prime[MAXN];

void init()
{
    memset(prime, true, sizeof(prime));
    for(int i=0;i<MAXN;++i)
        a[i] = i;
    for(int i=2;i<MAXN;++i)
        if(prime[i])
        {
            a[i] = i - 1;
            for(int j=2*i;j<MAXN;j+=i)
            {
                prime[j] = false;
                a[j] = a[j] * (i-1) / i;
            }
        }
    for(int i=3;i<MAXN;++i)
        a[i] += a[i-1];
}

int main()
{
    int n;
    init();
    while(scanf("%d", &n), n)
    {
        printf("%lld\n", a[n]);
    }
    return 0;
}
