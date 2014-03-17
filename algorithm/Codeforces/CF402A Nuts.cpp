#include <cstdio>

int main()
{
    int k, a, b, v;
    int ans;
    scanf("%d%d%d%d", &k, &a, &b, &v);
    for (ans = 1; ; ++ans)
    {
        if (b >= k - 1)
        {
            a -= v * k;
            b -= k - 1;
        }
        else
        {
            a -= v * (b + 1);
            b = 0;
        }
        if (a <= 0)
        {
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
