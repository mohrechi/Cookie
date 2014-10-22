#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 47000;
const int MAXM = 1000000 + 10;

bool isPrime[MAXM];
long long prime[MAXN], primeNum;

void init()
{
    for (long long i = 3; i < MAXN; i += 2)
    {
        isPrime[i] = true;
    }
    for (long long i = 3; i < MAXN; i += 2)
    {
        if (isPrime[i])
        {
            for (long long j = i + i; j < MAXN; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    primeNum = 1;
    prime[0] = 2;
    for (long long i = 3; i < MAXN; i += 2)
    {
        if (isPrime[i])
        {
            prime[primeNum++] = i;
        }
    }
}

int main()
{
    long long L, U;
    init();
    while (cin >> L >> U)
    {
        for (long long i = 0; i <= U - L; ++i)
        {
            isPrime[i] = true;
        }
        if (L == 1)
        {
            isPrime[0] = false;
        }
        for (long long i = 0; i < primeNum && prime[i] * prime[i] <= U; ++i)
        {
            long long t = L / prime[i];
            for (long long j = prime[i] * (t <= 1 ? 2 : t); j <= U; j += prime[i])
            {
                if (j >= L)
                {
                    isPrime[j - L] = false;
                }
            }
        }
        long long minDist = U - L + 1, minL, minU;
        long long maxDist = -1, maxL, maxU;
        long long last = -1;
        for (long long i = 0; i <= U - L; ++i)
        {
            if (isPrime[i])
            {
                if (last != -1)
                {
                    long long d = i - last;
                    if (d < minDist)
                    {
                        minL = last + L;
                        minU = i + L;
                        minDist = d;
                    }
                    if (d > maxDist)
                    {
                        maxL = last + L;
                        maxU = i + L;
                        maxDist = d;
                    }
                }
                last = i;
            }
        }
        if (maxDist == -1)
        {
            cout << "There are no adjacent primes." << endl;
        }
        else
        {
            cout << minL << "," << minU << " are closest, ";
            cout << maxL << "," << maxU << " are most distant." << endl;
        }
    }
    return 0;
}
