#include <cstdio>

int main()
{
    int n, a, b, c, num;
    while(~scanf("%d", &n))
    {
        num = 0;
        while(n--)
        {
            scanf("%d%d%d", &a, &b, &c);
            a += b += c;
            num += a > 1;
        }
        printf("%d\n", num);
    }
    return 0;
}
