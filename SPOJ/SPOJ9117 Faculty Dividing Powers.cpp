#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXP = 1e6 + 5;
const int MAXF = 100;

bool isPrime[MAXP];
int primeNum, prime[MAXP];

void init()
{
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 4; i < MAXP; i += 2)
    {
        isPrime[i] = false;
    }
    for (int i = 3; i < MAXP; i += 2)
    {
        for (int j = 3; i * j < MAXP; j += 2)
        {
            isPrime[i * j] = false;
        }
    }
    for (int i = 2; i < MAXP; ++i)
    {
        if (isPrime[i])
        {
            prime[primeNum++] = i;
        }
    }
}

int factorNum;
long long factor[MAXF];
long long factorCnt[MAXF];

void divide(long long num)
{
    factorNum = 0;
    for (int i = 0; i < primeNum && prime[i] <= num; ++i)
    {
        if (num % prime[i] == 0)
        {
            factorCnt[factorNum] = 0;
            while (num % prime[i] == 0)
            {
                num /= prime[i];
                ++factorCnt[factorNum];
            }
            factor[factorNum++] = prime[i];
        }
    }
    if (num != 1)
    {
        factorCnt[factorNum] = 1;
        factor[factorNum++] = num;
    }
}

long long appear(long long n, long long p, long long k)
{
    long long num = 0;
    long long ret = 0;
    long long t = p;
    while (t <= n)
    {
        num += n / t;
        ret += num / k;
        num %= k;
        if (n / p >= t)
        {
            t *= p;
        }
        else
        {
            break;
        }
    }
    return ret;
}

int main()
{
    int T;
    long long n, k;
    init();
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        divide(k);
        long long ans = 0x7fffffffffffffffLL;
        for (int i = 0; i < factorNum; ++i)
        {
            long long temp = appear(n, factor[i], factorCnt[i]);
            if (temp < ans)
            {
                ans = temp;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
