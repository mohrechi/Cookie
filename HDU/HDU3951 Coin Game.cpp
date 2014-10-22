#include <cstdio>

int main()
{
    int T, a, b;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%d", &a, &b);
        printf("Case %d: %s\n", t, (b == 1 && a & 1) || a <= b ? "first" : "second");
    }
    return 0;
}
