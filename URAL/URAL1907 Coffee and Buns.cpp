#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e6 + 10;
const int MAXM = 100;

bool isPrime[MAXN];
long long prime[MAXN], primeNum;

void initPrime()
{
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 4; i < MAXN; i += 2)
    {
        isPrime[i] = false;
    }
    for (int i = 3; i < MAXN; i += 2)
    {
        if (isPrime[i])
        {
            int k = i + i;
            for (int j = i + k; j < MAXN; j += k)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i < MAXN; ++i)
    {
        if (isPrime[i])
        {
            prime[primeNum++] = i;
        }
    }
}

long long divisor[MAXN], divisorNum;

void getDivisor(long long x)
{
    divisorNum = 0;
    for (int i = 0; i < primeNum && prime[i] * prime[i] <= x; ++i)
    {
        if (x % prime[i] == 0)
        {
            divisor[divisorNum++] = prime[i];
            while (x % prime[i] == 0)
            {
                x /= prime[i];
            }
        }
    }
    if (x > 1)
    {
        divisor[divisorNum++] = x;
    }
}

int main()
{
    long long a, n;
    initPrime();
    while (cin >> a >> n)
    {
        long long ans = 0;
        if (a & 1)
        {
            ans = (n + 1) / 2;
        }
        else
        {
            ans = n / 2;
        }
        getDivisor(a);
        int m = 1 << divisorNum;
        for (int i = 1; i < m; ++i)
        {
            bool positive = false;
            long long div = 1;
            for (int j = 0; j < divisorNum; ++j)
            {
                if (i & (1 << j))
                {
                    positive = !positive;
                    div *= divisor[j];
                }
            }
            long long num = 0;
            if (a & 1)
            {
                if (div & 1)
                {
                    num = n / (div * 2);
                }
                else
                {
                    num = n / div;
                }
            }
            else
            {
                if (div & 1)
                {
                    num = (n + div) / (div * 2);
                }
            }
            if (positive)
            {
                ans += num;
            }
            else
            {
                ans -= num;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
