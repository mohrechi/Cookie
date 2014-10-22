#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = (1000001 >> 2) + 10;

bool isPrime[MAXN];
int firstPrime[MAXN], cnt[MAXN];

void init()
{
    memset(isPrime, true, sizeof(isPrime));
    for (int i = 5; (i >> 2) < MAXN; i += 4)
    {
        if (isPrime[i >> 2])
        {
            for (int j = 5; (i * j) >> 2 < MAXN; j += 4)
            {
                isPrime[(i * j) >> 2] = false;
                if (firstPrime[(i * j) >> 2] == 0)
                {
                    firstPrime[(i * j) >> 2] = i;
                }
            }
        }
    }
    for (int i = 5; (i >> 2) < MAXN; i += 4)
    {
        if (!isPrime[i >> 2] && isPrime[(i / firstPrime[i >> 2]) >> 2])
        {
            cnt[i >> 2] = cnt[(i >> 2) - 1] + 1;
        }
        else
        {
            cnt[i >> 2] = cnt[(i >> 2) - 1];
        }
    }
}

int main()
{
    int n;
    init();
    while (scanf("%d", &n), n)
    {
        printf("%d %d\n", n, cnt[n >> 2]);
    }
    return 0;
}
