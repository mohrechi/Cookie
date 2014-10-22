#include <cstdio>

int main()
{
    int t, b;
    char s[20];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s", &b, s);
        long long ans = 0;
        for (int i = 0; s[i]; ++i)
        {
            ans = ans * b + s[i] - '0';
        }
        printf("%lld\n", ans);
    }
    return 0;
}
