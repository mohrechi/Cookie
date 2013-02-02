#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000005;
const int MAXM = 1005;

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
    primeNumber = 0;
    for(int i=2;i<MAXM;++i)
    {
        if(isPrime[i])
        {
            prime[primeNumber++] = i;
        }
    }
}

int main()
{
    int n;
    init();
    while(~scanf("%d", &n))
    {
        int count = 0;
        for(int i=0;i<primeNumber;++i)
        {
            while(n % prime[i] == 0)
            {
                n /= prime[i];
                ++ count;
            }
        }
        if(n > 1)
        {
            ++ count;
        }
        printf("%d\n", count);
    }
    return 0;
}
