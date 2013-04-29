#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

long long pow(long long x, long long y)
{
    long long res = 1;
    long long bit = x;
    for (int i = 0; (1 << i) <= y; ++i)
    {
        if (y & (1 << i))
        {
            res = (res * bit) % MOD;
        }
        bit = (bit * bit) % MOD;
    }
    return res;
}

int main()
{
    long long n;
    while (~scanf("%lld", &n))
    {
        printf("%lld\n", pow(n, n - 2));
    }
    return 0;
}
