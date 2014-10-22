#include <cstdio>

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        bool flag = true;
        ++m;
        for (int i = 0; i < n - m; ++i)
        {
            if (flag)
            {
                flag = false;
            }
            else
            {
                putchar(' ');
            }
            printf("%d", i + 1);
        }
        for (int i = 0; i < m; ++i)
        {
            if (flag)
            {
                flag = false;
            }
            else
            {
                putchar(' ');
            }
            printf("%d", n - i);
        }
        putchar('\n');
    }
    return 0;
}
