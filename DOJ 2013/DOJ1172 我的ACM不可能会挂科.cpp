#include <cstdio>
const int MAXN = 1e5 + 5;

char s[MAXN];
int sum[MAXN];

int main()
{
    int n, l, r;
    while (~scanf("%s", s + 1))
    {
        for (int i = 1; s[i]; ++i)
        {
            sum[i] = sum[i - 1] + (s[i] == s[i + 1]);
        }
        scanf("%d", &n);
        while (n--)
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", sum[r - 1] - sum[l - 1]);
        }
    }
    return 0;
}
