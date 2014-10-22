#include <cstdio>
#include <cstring>

int main()
{
    int T, n;
    __int64 a, b, x, y;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d", &n);
        a = b = 0;
        while (n--)
        {
            scanf("%I64d%I64d", &x, &y);
            while (x > 1 && y > 1)
            {
                x >>= 1;
                y >>= 1;
            }
            if (x == 1)
            {
                b += y - 1;
            }
            if (y == 1)
            {
                a += x - 1;
            }
        }
        printf("Case %d: %s\n", t, a > b ? "Alice" : "Bob");
    }
    return 0;
}
