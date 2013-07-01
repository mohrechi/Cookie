#include <cstdio>

int main()
{
    int a, b, c, n;
    while(scanf("%d%d",&a,&b), a||b)
    {
        c = n = 0;
        while(a || b)
        {
            c += (a % 10) + (b % 10);
            a /= 10;
            b /= 10;
            if(c > 9)
            {
                c = 1;
                ++ n;
            }
            else c = 0;
        }
        if(n) printf("%d", n);
        else printf("No");
        printf(" carry operation");
        if(n > 1) printf("s");
        printf(".\n");
    }
}
