#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 9901;

int pow(int x, int y)
{
    int res = 1, tmp = x % MOD;
    for (int i = 0; (1 << i) <= y; ++i)
    {
        if (y & (1 << i))
        {
            res = res * tmp % MOD;
        }
        tmp = tmp * tmp % MOD;
    }
    return res;
}

int inverse(int a)
{
    return pow(a, MOD - 2);
}

int sum(int p, int cnt)
{
    if ((p - 1) % MOD == 0)
    {
        return cnt % MOD;
    }
    return (pow(p, cnt) + MOD - 1) % MOD * inverse(p - 1) % MOD;
}

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 1;
    for (int i = 2; i * i <= a; ++i)
    {
        if (a % i == 0)
        {
            int cnt = 0;
            while (a % i == 0)
            {
                a /= i;
                ++cnt;
            }
            ans = ans * sum(i, cnt * b + 1) % MOD;
        }
    }
    if (a > 1)
    {
        ans = ans * sum(a, b + 1) % MOD;
    }
    printf("%d\n", ans);
    return 0;
}
