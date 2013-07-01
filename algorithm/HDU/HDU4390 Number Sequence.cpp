#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int MAXB = 1000001;
const int MAXP = 80000;
const int MOD = 1000000007;

int n;
int b[MAXN];
int c[MAXN][MAXN];
bool isPrime[MAXB];
int primeNumber;
int prime[MAXP];
int primeCount[MAXP];
int maxPrimeIndex;

void init()
{
    c[0][0] = 1;
    for(int i=1;i<MAXN;++i)
    {
        c[i][0] = c[i][i] = 1;
        for(int j=1;j<i;++j)
        {
            c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
        }
    }
    memset(isPrime, true, sizeof(isPrime));
    for(int i=4;i<MAXB;i+=2)
    {
        isPrime[i] = false;
    }
    for(int i=3;i<MAXB;i+=2)
    {
        for(int j=3;i*j<MAXB;j+=2)
        {
            isPrime[i*j] = false;
        }
    }
    primeNumber = 0;
    for(int i=2;i<MAXB;++i)
    {
        if(isPrime[i])
        {
            prime[primeNumber++] = i;
        }
    }
}

void divide(int b)
{
    for(int i=0;i<primeNumber && i<=b;++i)
    {
        while(b % prime[i] == 0)
        {
            ++primeCount[i];
            b /= prime[i];
            if(prime[i] > prime[maxPrimeIndex])
            {
                maxPrimeIndex = i;
            }
        }
    }
}

__int64 getNumber(int x)
{
    __int64 res = c[n][n-x];
    for(int i=0;i<=maxPrimeIndex;++i)
    {
        if(primeCount[i])
        {
        res = (res * c[x + primeCount[i] - 1][x - 1]) % MOD;
        }
    }
    return res;
}

int solve()
{
    __int64 res = 0;
    bool flag = true;
    for(int i=n;i>=0;--i)
    {
        if(flag)
        {
            res = (res + getNumber(i)) % MOD;
        }
        else
        {
            res = (res + MOD - getNumber(i)) % MOD;
        }
        flag = ! flag;
    }
    return (int)res;
}

int main()
{
    init();
    while(~scanf("%d", &n))
    {
        memset(primeCount, 0, sizeof(primeCount));
        maxPrimeIndex = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &b[i]);
            divide(b[i]);
        }
        printf("%d\n", solve());
    }
    return 0;
}
