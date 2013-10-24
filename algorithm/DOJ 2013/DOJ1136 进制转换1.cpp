#include <cstdio>

int main()
{
    int t, b, n, ans[100], l;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &b, &n);
        l = 0;
        while (n)
        {
            ans[l++] = n % b;
            n /= b;
        }
        for (int i = l - 1; i >= 0; --i)
        {
            printf("%d", ans[i]);
        }
        putchar('\n');
    }
    return 0;
}
