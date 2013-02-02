#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;

long long factor[110], cnt;

long long Mul_Mod(long long a, long long b, long long c)
{
    if (b == 0)
    {
        return 0;
    }
    long long ans = Mul_Mod(a, b / 2, c);
    ans = (ans * 2) % c;
    if (b % 2)
    {
        ans = (ans + a) % c;
    }
    return ans;
}
long long Pow_Mod(long long a, long long b, long long c)
{
    if (b == 0)
    {
        return 1;
    }
    long long x = Pow_Mod(a, b / 2, c);
    if (x == 0)
    {
        return 0;
    }
    long long y = Mul_Mod(x, x, c);
    if (y == 1 && x != 1 && x != c - 1)
    {
        return 0;
    }
    if (b % 2)
    {
        y = Mul_Mod(y, a, c);
    }
    return y;
}
bool Miller_rabin(long long n, int timenum = 10)
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2)
    {
        return true;
    }
    while (timenum--)
    {
        if (Pow_Mod(rand() % (n - 2) + 2, n - 1, n) != 1)
        {
            return false;
        }
    }
    return true;
}

long long Gcd(long long a, long long b)
{
    long long t;
    while (b)
    {
        t = a;
        a = b;
        b = t % b;
    }
    return a;
}
void Pollard(long long n);

void Factor(long long n)
{
    long long d = 2;
    while (true)
    {
        if (n % d == 0)
        {
            Pollard(d);
            Pollard(n / d);
            return;
        }
        d++;
    }
}
void Pollard(long long n)
{
    if (n <= 0)
    {
        return;
    }
    if (n == 1)
    {
        return;
    }
    if (Miller_rabin(n))
    {
        factor[cnt++] = n;
        return;
    }
    long long i = 0, k = 2, x, y, d;
    x = y = rand() % (n - 1) + 1;
    while (i++ < 123456)
    {
        x = (Mul_Mod(x, x, n) + n - 1) % n;
        d = Gcd((y - x + n) % n, n);
        if (d != 1)
        {
            Pollard(d);
            Pollard(n / d);
            return;
        }
        if (i == k)
        {
            y = x;
            k *= 2;
        }
    }
    Factor(n);
}

int main()
{
    //freopen("std.in", "r", stdin);
    //freopen("out2.txt", "w", stdout);
    long long n;
    while(~scanf("%lld", &n))
    {
        if(n == 1)
        {
            printf("1\n");
        }
        else if(Miller_rabin(n))
        {
            printf("%lld\n", ((n % MOD) * ((n - 1) % MOD) / 2) % MOD);
        }
        else
        {
            cnt = 0;
            Pollard(n);
            sort(factor, factor + cnt);
            long long sum = factor[0] - 1;
            for(int i=1;i<cnt;++i)
            {
                if(factor[i] == factor[i - 1])
                {
                    sum = (sum * factor[i]) % MOD;
                }
                else
                {
                    sum = (sum * (factor[i] - 1)) % MOD;
                }
            }
            printf("%lld\n", ((n % MOD) * (sum % MOD) / 2) % MOD);
        }
    }
    return 0;
}
