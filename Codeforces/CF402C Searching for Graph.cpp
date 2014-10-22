#include <cstdio>

int main()
{
    int t, n, p;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &p);
        int cnt = 2 * n + p;
        for (int i = 1; i <= n && cnt; ++i)
        {
            for (int j = i + 1; j <= n && cnt; ++j, --cnt)
            {
                printf("%d %d\n", i, j);
            }
        }
    }
    return 0;
}
