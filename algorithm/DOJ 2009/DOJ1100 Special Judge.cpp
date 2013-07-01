#include <cstdio>

int main()
{
    int n, m;
    while(~scanf("%d%d",&n,&m))
    {
        printf("%d", m-n+1);
        for(int i=1;i<n;++i)
        {
            printf(" 1");
        }
        printf("\n");
    }
    return 0;
}
