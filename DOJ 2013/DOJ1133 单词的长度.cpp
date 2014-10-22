#include <cstdio>
#include <cstring>

int main()
{
    int t, n, m;
    char s[100];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        m = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", s);
            m += strlen(s);
        }
        printf("%.2lf\n", 1.0 * m / n);
    }
    return 0;
}
