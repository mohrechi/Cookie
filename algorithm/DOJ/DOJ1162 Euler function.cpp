#include <cstdio>
#include <cstring>
#include <math.h>
static const int MAXP = 4000000;
static const int MAXN = 400000;
bool isPrime[MAXP];
long long prime[MAXN];
int primeNumber;
long long allPrime[MAXN];
long long allPrimeNumber;
long long tm;

inline long long max(long long x, long long y)
{
    return x > y ? x : y;
}

void makePrime()
{
    memset(isPrime, true, sizeof(isPrime));
    for(int i=4;i<MAXP;i+=2)
        isPrime[i] = false;
    for(int i=3;i*i<MAXP;++i)
    {
        for(int j=i<<1;j<MAXP;j+=i)
        {
            isPrime[j] = false;
        }
    }
    primeNumber = 0;
    for(int i=2;i<MAXP;++i)
    {
        if(isPrime[i])
        {
            prime[primeNumber++] = i;
        }
    }
}

long long ans;
void dfs(int index, long long factor, bool carry)
{
    if(index == allPrimeNumber)
    {
        if(factor == 1) return;
        if(carry) ans -= tm / factor;
        else ans += tm / factor;
        return;
    }
    dfs(index + 1, factor, carry);
    dfs(index + 1, factor * allPrime[index], !carry);
}

int main()
{
    long long n, m;
    makePrime();
    while(~scanf("%lld%lld",&n,&m))
    {
        allPrimeNumber = 0;
        tm = m;
        bool flag;
        for(int i=0;prime[i]<=max(n, m) && i < primeNumber;++i)
        {
            flag = false;
            while(n % prime[i] == 0)
            {
                flag = true;
                n /= prime[i];
            }
            while(m % prime[i] == 0)
            {
                flag = true;
                m /= prime[i];
            }
            if(flag)
            {
                allPrime[allPrimeNumber++] = prime[i];
            }
        }
        if(n > 1) allPrime[allPrimeNumber++] = n;
        if(m > 1) allPrime[allPrimeNumber++] = m;
        ans = tm;
        dfs(0, 1LL, false);
        printf("%lld\n", ans);
    }
    return 0;
}
