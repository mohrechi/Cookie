#include <cstdio>

int main()
{
    int a, b, c;
    while (~scanf("%d%d%d", &a, &b, &c))
    {
        int ans = -1;
        for (int i = 10; i <= 100; ++i)
        {
            if (i % 3 == a && i % 5 == b && i % 7 == c)
            {
                ans = i;
                break;
            }
        }
        if (ans == -1)
        {
            printf("No answer\n");
        }
        else
        {
            printf("%d\n", ans);
        }
    }
    return 0;
}
