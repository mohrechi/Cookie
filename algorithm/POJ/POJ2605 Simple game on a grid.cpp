#include <cstdio>

int main()
{
    int m, n;
    while(~scanf("%d%d",&m,&n))
    {
        if(n > m)
            m ^= n, n ^= m, m ^= n;
        if(n == 1 || n == 2)
            printf("%d\n", (m+1)>>1);
        else if(n % 3 == 0 || m % 3 == 0)
            printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}
