#include <cstdio>
#include <cstring>

bool isPrime[1000010];
__int64 prime[100000];
int primeNumber;

void init()
{
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;
    for(int i=4;i<1000010;i+=2)
    {
        isPrime[i] = false;
    }
    for(int i=3;i<=1000;i+=2)
    {
        for(int j=3;i*j<1000010;j+=2)
        {
            isPrime[i*j] = false;
        }
    }
    primeNumber = 0;
    for(int i=0;i<1000010;++i)
    {
        if(isPrime[i])
        {
            prime[primeNumber++] = i;
        }
    }
}

bool judge(__int64 a, __int64 b)
{
    for(int i=0;i<primeNumber;++i)
    {
        if(a % prime[i] == 0)
        {
            if(b % prime[i] != 0)
            {
                return false;
            }
            while(a % prime[i] == 0)
            {
                a /= prime[i];
            }
        }
        if(prime[i] > a)
        {
            break;
        }
    }
    if(a > 1)
    {
        return b % a == 0;
    }
    return true;
}

int main()
{
    int t;
    init();
    __int64 a, b;
    scanf("%d", &t);
    for(int k=1;k<=t;++k)
    {
        scanf("%I64d%I64d", &a, &b);
        printf("Case #%d: ", k);
        if(judge(a, b))
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
