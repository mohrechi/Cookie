#include <cstdio>

int main()
{
    int m, n;
    while(~scanf("%d%d", &n, &m))
    {
        printf("%d\n", (n * m) >> 1);
    }
    return 0;
}
