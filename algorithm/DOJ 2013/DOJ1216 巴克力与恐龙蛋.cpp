#include <cstdio>

int main()
{
    int t, n, a, b;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        a = 0;
        while (n--)
        {
            scanf("%d", &b);
            a ^= b;
        }
        printf("%d\n", a == 0 ? -1 : a);
    }
    return 0;
}
