#include <cstdio>

int main()
{
    int t;
    long long n, l, r;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%I64d%I64d%I64d", &n, &l, &r);
        if (n / l * r >= n)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}
