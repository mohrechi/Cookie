#include <cstdio>

int main()
{
    long long a[16];
    a[0] = 1;
    for (int i = 1; i <= 15; ++i)
    {
        a[i] = a[i - 1] * i;
    }
    int n;
    while (~scanf("%d", &n))
    {
        printf("%lld\n", a[n]);
    }
    return 0;
}
