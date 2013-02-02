#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000;

bool isPrime[MAXN];
int prime[MAXN / 2], primeNumber;

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
            prime[primeNumber ++] = i;
        }
    }
}

bool judge(long long x)
{
    for(int i=0;(long long)prime[i]*prime[i]<=x;++i)
    {
        if(x % prime[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    long long n;
    init();
    while(~scanf("%lld", &n))
    {
        if(judge(n))
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    return 0;
}
