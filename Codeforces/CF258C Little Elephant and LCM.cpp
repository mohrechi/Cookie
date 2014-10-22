#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MAXM = 320;
const int MOD = 1000000007;

int n, maxn;
int num[MAXN];
int totalNum[MAXN];
int primeFactorNumber;
int primeFactor[MAXN];
int primeCount[MAXN];
int factorNumber;
int factor[MAXN];

long long power2[MAXN];

bool isPrime[MAXM];
int prime[MAXM], primeNumber;

void init()
{
    memset(isPrime, true, sizeof(isPrime));
    for(int i=4;i<MAXM;i+=2)
    {
        isPrime[i] = false;
    }
    for(int i=3;i<MAXM;i+=2)
    {
        for(int j=3;i*j<MAXM;j+=2)
        {
            isPrime[i * j] = false;
        }
    }
    for(int i=2;i<MAXM;++i)
    {
        if(isPrime[i])
        {
            prime[primeNumber++] = i;
        }
    }
    power2[0] = 1;
    for(int i=1;i<MAXN;++i)
    {
        power2[i] = (power2[i - 1] << 1) % MOD;
    }
}

void getPrimeFactor(int x)
{
    primeFactorNumber = 0;
    for(int i=0;prime[i] * prime[i]<=x;++i)
    {
        if(x % prime[i] == 0)
        {
            primeFactor[primeFactorNumber] = prime[i];
            primeCount[primeFactorNumber] = 0;
            while(x % prime[i] == 0)
            {
                x /= prime[i];
                ++ primeCount[primeFactorNumber];
            }
            ++ primeFactorNumber;
        }
    }
    if(x > 1)
    {
        primeFactor[primeFactorNumber] = x;
        primeCount[primeFactorNumber++] = 1;
    }
}

void getFactor(int pos, int total)
{
    if(pos == primeFactorNumber)
    {
        factor[factorNumber++] = total;
        return;
    }
    int mul = 1;
    for(int i=0;i<=primeCount[pos];++i)
    {
        getFactor(pos + 1, total * mul);
        mul *= primeFactor[pos];
    }
}

void getFactor()
{
    factorNumber = 0;
    getFactor(0, 1);
    sort(factor, factor + factorNumber);
}

long long pow_mod(long long x, long long y)
{
    long long res = 1;
    long long asi = x;
    for(long long i=0;(1<<i)<=y;++i)
    {
        if(y & (1 << i))
        {
            res = (res * asi) % MOD;
        }
        asi = (asi * asi) % MOD;
    }
    return res;
}

int main()
{
    int a;
    init();
    while(~scanf("%d", &n))
    {
        maxn = 0;
        memset(num, 0, sizeof(num));
        memset(totalNum, 0, sizeof(totalNum));
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            ++ num[a];
            maxn = max(maxn, a);
        }
        for(int i=maxn;i>=0;--i)
        {
            totalNum[i] = num[i] + totalNum[i + 1];
        }
        long long ans = 1;
        for(int i=2;i<=maxn;++i)
        {
            getPrimeFactor(i);
            getFactor();
            long long way = (pow_mod(factorNumber, totalNum[i]) - pow_mod(factorNumber - 1, totalNum[i]) + MOD) % MOD;
            for(int j=factorNumber-1;j>=0;--j)
            {
                way = (way * pow_mod(j + 1, totalNum[factor[j]] - totalNum[factor[j+1]])) % MOD;
            }
            ans = (ans + way) % MOD;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
