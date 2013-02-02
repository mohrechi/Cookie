#include <cstdio>
#include <cstring>
const int MAXN = 105;

int n, a[MAXN];
int m, b[MAXN];

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        int count = 0;
        b[0] = 0, m = 0;
        for(int i=0;i<n;++i)
        {
            if(a[i] >= 0)
            {
                ++ b[m];
            }
            else
            {
                if(count < 2)
                {
                    ++ b[m];
                    ++ count;
                }
                else
                {
                    count = 1;
                    b[++m] = 1;;
                }
            }
        }
        printf("%d\n", m + 1);
        for(int i=0;i<=m;++i)
        {
            if(i)
            {
                printf(" ");
            }
            printf("%d", b[i]);
        }
        printf("\n");
    }
    return 0;
}
