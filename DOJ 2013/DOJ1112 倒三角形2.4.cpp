#include <cstdio>

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                putchar(' ');
            }
            int a = (n << 1) - ((i << 1) + 1);
            for (int j = 0; j < a; ++j)
            {
                putchar('#');
            }
            putchar('\n');
        }
    }
    return 0;
}
