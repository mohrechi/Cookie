#include <cstdio>
#include <cstring>
const int MAXN = 100;

int main()
{
    int n;
    long long a[MAXN];
    a[0] = 0;
    a[1] = 1;
    for (int i = 2; i < MAXN; ++i)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    while (scanf("%d", &n), n + 1)
    {
        printf("%lld\n", a[n]);
    }
    return 0;
}
