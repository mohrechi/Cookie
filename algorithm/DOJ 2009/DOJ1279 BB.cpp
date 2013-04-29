#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;

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

int main()
{
    int t, n;
    init();
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        int num = 0;
        for(int i=0;i<primeNumber;++i)
        {
            if(n % prime[i] == 0)
            {
                if(++num > 2)
                {
                    break;
                }
                while(n % prime[i] == 0)
                {
                    n /= prime[i];
                }
            }
        }
        if(n != 1)
        {
            ++num;
        }
        if(num == 2)
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
