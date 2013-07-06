#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MOD = 1000000007;

char s[MAXN];

long long pow(long long x, long long y)
{
    long long res = 1;
    for (int i = 0; (1LL << i) <= y; ++i)
    {
        if (y & (1LL << i))
        {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
    }
    return res;
}

long long get(long long n, long long k)
{
    if (k == 1)
    {
        return 1;
    }
    long long half = get(n, k >> 1);
    long long res = (half * (pow(2, n * (k >> 1)) + 1)) % MOD;
    if (k & 1)
    {
        res = (res + pow(2, (k - 1) * n)) % MOD;
    }
    return res;
}

int main()
{
    int n, k;
    while (~scanf("%s%d", s, &k))
    {
        long long pow2 = 1;
        long long ans = 0;
        for (n = 0; s[n]; ++n)
        {
            if (s[n] == '5' || s[n] == '0')
            {
                ans = (ans + pow2) % MOD;
            }
            pow2 = (pow2 << 1) % MOD;
        }
        ans = (ans * get(n, k)) % MOD;
        cout << ans << endl;
    }
    return 0;
}
