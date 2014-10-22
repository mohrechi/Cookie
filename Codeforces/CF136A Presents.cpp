#include <cstdio>
#include <cstring>
const int MAXN = 105;

int n, a[MAXN], b[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &a[i]);
            b[a[i]] = i;
        }
        for(int i=1;i<=n;++i)
        {
            if(i > 1)
            {
                printf(" ");
            }
            printf("%d", b[i]);
        }
        printf("\n");
    }
    return 0;
}
