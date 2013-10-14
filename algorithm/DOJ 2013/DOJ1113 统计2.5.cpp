#include <cstdio>

int main()
{
    int n, m, a, c;
    while (~scanf("%d%d", &n, &m))
    {
        c = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &a);
            if (a < m)
            {
                ++c;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
