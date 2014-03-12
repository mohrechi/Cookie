#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;

long long n, m;
long long l, r, p;
long long num[MAXN], factor[MAXN][6];
long long ans;

long long calc(long long low, long long high, long long m)
{
	high = high / m;
	low = (low + m - 1) / m;
	return ((high - low + 1) * (n + 1) - m * ((high * (high + 1) - (low - 1) * low) / 2)) % p;
}

int main()
{
    scanf("%I64d%I64d", &n, &m);
    scanf("%I64d%I64d%I64d", &l, &r, &p);
    for (int i = 2; i <= m; ++i)
    {
        if (num[i] == 0)
        {
            for (int j = i; j <= m; j += i)
            {
                factor[j][num[j]++] = i;
            }
        }
    }
    long long low = l, high = r;
    long long minn = min(m, r);
    for (long long k = 1; k <= minn; ++k)
    {
        while (low > 1 && l * l - k * k <= (low - 1) * (low - 1))
        {
            --low;
        }
        while (r * r - k * k < high * high)
        {
            --high;
        }
        if (low <= high && low <= n)
        {
            long long a = 0;
            long long t = 1 << num[k];
            for (int i = 0; i < t; ++i)
            {
                long long temp = i;
                long long p1 = 1, p2 = 1;
                for (int j = 0; j < num[k]; ++j)
                {
                    if (temp & 1)
                    {
                        p1 *= factor[k][j];
                        p2 *= -1;
                    }
                    temp >>= 1;
                }
                a += p2 * calc(low, min(high, n), p1);
            }
            ans = (ans + a * (m - k + 1)) % p;
            if (ans < 0)
            {
                ans += p;
            }
        }
    }
    if (l <= 1 && r >= 1)
    {
        ans = ((ans << 1) + m * (n + 1) + n * (m + 1)) % p;
    }
    else
    {
        ans = (ans << 1) % p;
    }
    printf("%I64d\n", ans);
    return 0;
}
