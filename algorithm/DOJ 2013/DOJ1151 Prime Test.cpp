#include <cstdio>

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        bool flag = true;
        for (int i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
            {
                printf("%d\n", i);
                flag = false;
                break;
            }
        }
        if (flag)
        {
            printf("Prime\n");
        }
    }
    return 0;
}
