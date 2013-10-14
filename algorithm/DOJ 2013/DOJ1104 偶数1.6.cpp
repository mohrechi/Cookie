#include <cstdio>

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        if (n & 1)
        {
            printf("no\n");
        }
        else
        {
            printf("yes\n");
        }
    }
    return 0;
}
