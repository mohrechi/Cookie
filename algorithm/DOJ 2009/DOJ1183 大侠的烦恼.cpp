#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000;

bool isPrime[MAXN];
int prime[MAXN], primeNumber;

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
            isPrime[i * j] = false;
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

int getNum(int x)
{
    int count = 0;
    for(int i=0;i<primeNumber && prime[i] * prime[i] <= x;++i)
    {
        while(x % prime[i] == 0)
        {
            ++ count;
            x /= prime[i];
        }
    }
    if(x > 1)
    {
        ++ count;
    }
    return count;
}

int main()
{
    int t, n, m;
    init();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        n = abs(n);
        int mm = getNum(n);
        if(mm >= m)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
