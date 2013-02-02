#include <cstdio>
#include <cstring>
const int MAXN = 205;
int g[MAXN][MAXN];
char s[128];

int main()
{
    int n, u, v;
    while(scanf("%d", &n), n)
    {
        memset(g, 0, sizeof(g));
        while(scanf("%d%d",&u,&v), u||v)
        {
            scanf("%s", s);
            for(int i=0;s[i];++i)
            {
                g[u][v] |= 1<<(s[i] - 'a');
            }
        }
        for(int k=1;k<=n;++k)
        {
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    g[i][j] |= g[i][k] & g[k][j];
                }
            }
        }
        while(scanf("%d%d",&u,&v), u||v)
        {
            if(g[u][v])
            {
                for(int i=0;i<=26;++i)
                {
                    if(g[u][v] & (1<<i))
                    {
                        putchar('a' + i);
                    }
                }
            }
            else
            {
                printf("-");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
