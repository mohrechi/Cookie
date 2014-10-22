#include <cstdio>

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    int T, n;
    long long a, b, c;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%lld%lld%lld", &n, &a, &b, &c);
        a = a / gcd(a, b) * b;
        c = c / gcd(c, b) * b;
        b = a / gcd(a, c) * c;
        printf("%d\n", n - n / b);
    }
    return 0;
}
