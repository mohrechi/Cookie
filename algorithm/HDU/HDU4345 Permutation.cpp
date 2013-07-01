#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 1001;

int n, prime[MAXN], primeNumber;
bool isPrime[MAXN];
__int64 ans[MAXN];
__int64 a[MAXN][MAXN];

void initPrime()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
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
    for(int i=0;i<MAXN;++i)
    {
        if(isPrime[i])
        {
            prime[primeNumber++] = i;
        }
    }
}

void initDecomposition()
{
    memset(a, 0, sizeof(a));
    for(int i=2;i<MAXN;++i)
    {
        for(int j=0;j<primeNumber;++j)
        {
            if(prime[j] > i)
            {
                break;
            }
            else
            {
                int temp = 1;
                while(temp <= i)
                {
                    temp *= prime[j];
                    if(i - temp > 0)
                    {
                        for(int k=j+1;k<primeNumber;++k)
                        {
                            a[i][j] += a[i-temp][k];
                        }
                    }
                    else if(i - temp == 0)
                    {
                        a[i][j] += 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
    }
}

void initAnswer()
{
    for(int i=2;i<MAXN;++i)
    {
        for(int j=1;j<primeNumber;++j)
        {
            a[i][0] += a[i][j];
        }
    }
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2;i<MAXN;++i)
    {
        ans[i] = ans[i-1] + a[i][0];
    }
}

void init()
{
    initPrime();
    initDecomposition();
    initAnswer();
}

int main()
{
    init();
    while(~scanf("%d", &n))
    {
        printf("%I64d\n", ans[n]);
    }
    return 0;
}
