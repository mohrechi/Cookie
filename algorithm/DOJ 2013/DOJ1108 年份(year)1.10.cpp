#include <cstdio>

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        if (n % 100 == 0)
        {
            if (n % 400 == 0)
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        else if (n % 4 == 0)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
