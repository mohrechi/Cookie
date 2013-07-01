#include <cstdio>
#include <cstring>
const int MAXN = 1000;

int divide[MAXN];

int main()
{
    int n, m, k;
    while(~scanf("%d%d%d", &n, &m, &k))
    {
        if(n < m + k - 1 || n > m * k)
        {
            printf("-1\n");
        }
        else
        {
            for(int i=k;i>=1;--i)
            {
                if(i != k) printf(" ");
                printf("%d", i);
            }
            memset(divide, 0, sizeof(divide));
            int j = 0;
            for(int i=k+1;i<=n;++i,++j)
            {
                if(j >= m - 1)
                {
                    j = 0;
                }
                ++ divide[j];
            }
            j = k + 1;
            for(int i=0;i<m-1;++i)
            {
                for(int l=j+divide[i]-1;l>=j;--l)
                {
                    printf(" %d", l);
                }
                j += divide[i];
            }
            printf("\n");
        }
    }
    return 0;
}
