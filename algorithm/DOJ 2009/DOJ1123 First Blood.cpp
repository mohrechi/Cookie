#include <cstdio>

int main()
{
    int n,m,a,c;
    while(scanf("%d",&n), n)
    {
        scanf("%d",&m);
        c = 0;
        while(n--)
        {
            scanf("%d", &a);
            if(a >= m)
            {
                ++ c;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}
