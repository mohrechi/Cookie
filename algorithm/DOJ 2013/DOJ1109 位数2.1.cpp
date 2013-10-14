#include <cstdio>

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int c = 0;
        while (n)
        {
            ++c;
            n /= 10;
        }
        printf("%d\n", c);
    }
    return 0;
}
