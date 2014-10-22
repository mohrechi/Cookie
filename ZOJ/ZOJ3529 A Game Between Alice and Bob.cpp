#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
const int MAXM = 5000000 + 10;
const int MAXK = 5000;

bool notPrime[MAXK];
int primeNum, prime[MAXK];
int sg[MAXM], a, b[MAXN];

int main()
{
    int n, t = 0;
    for (int i = 2; i < MAXK; ++i)
    {
        if (!notPrime[i])
        {
            prime[primeNum++] = i;
            for (int j = i; j < MAXK; j += i)
            {
                notPrime[j] = true;
            }
        }
    }
    for (int i = 1; i < MAXM; ++i)
    {
        int t = i;
        for (int j = 0; j < primeNum && prime[j] * prime[j] <= t; ++j)
        {
            while (t % prime[j] == 0)
            {
                ++sg[i];
                t /= prime[j];
            }
        }
        if (t > 1)
        {
            ++sg[i];
        }
    }
    while (~scanf("%d", &n))
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            ans ^= (b[i] = sg[a]);
        }
        printf("Test #%d: ", ++t);
        if (ans)
        {
            for (int i = 0; i < n; ++i)
            {
                if (b[i] > (ans ^ b[i]))
                {
                    printf("Alice %d\n", i + 1);
                    break;
                }
            }
        }
        else
        {
            puts("Bob");
        }
    }
    return 0;
}
