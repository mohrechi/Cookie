#include <cstdio>
#include <cstring>
const int MAXN = 1000000;
const int MAXM = 80000;
const int MOD = 100000007;

bool isPrime[MAXN];
int prime[MAXM], primeNumber;

void init()
{
    memset(isPrime, true, sizeof(isPrime));
    for(int i=4;i<MAXN;i+=2)
    {
        isPrime[i] = false;
    }
    for(int i=3;i<MAXN;i+=2)
    {
        for(int j=3;i*j<MAXN;j+=2)
        {
            isPrime[i*j] = false;
        }
    }
    primeNumber = 0;
    for(int i=2;i<MAXN;++i)
    {
        if(isPrime[i])
        {
            prime[primeNumber++] = i;
        }
    }
}

long long value[MAXM];
int count[MAXM];
int countNumber;

void add(long long x)
{
    for(int i=0;i<countNumber;++i)
    {
        if(value[i] == x)
        {
            ++ count[i];
            return;
        }
    }
    value[countNumber] = x;
    count[countNumber] = 1;
    ++ countNumber;
}

void divide(long long x)
{
    for(int i=0;i<primeNumber && x > 1;++i)
    {
        while(x % prime[i] == 0)
        {
            x /= prime[i];
            add(prime[i]);
        }
    }
    if(x > 1)
    {
        add(x);
    }
}

long long getAns()
{
    long long ans = 1;
    for(int i=0;i<countNumber;++i)
    {
        ans = (ans * (count[i] + 1)) % MOD;
    }
    return ans;
}

int main()
{
    int n;
    init();
    while(~scanf("%d", &n))
    {
        long long a;
        countNumber = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%lld", &a);
            divide(a);
        }
        printf("%lld\n", getAns());
    }
    return 0;
}
