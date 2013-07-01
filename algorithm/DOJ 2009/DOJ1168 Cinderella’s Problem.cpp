#include <cstdio>
#include <cstring>
static const int MAXN = 205;

int t, n;
int m[MAXN][MAXN];
int dirX[] = {0, 0, 1, -1};
int dirY[] = {1, -1, 0, 0};

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(m, 0, sizeof(m));
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                scanf("%d", &m[i][j]);
        bool flag = true;
        int cur = 1;
        while(flag)
        {
            flag = false;
            for(int i=1;i<=n;++i)
            {
                for(int j=1;j<=n;++j)
                {
                    if(m[i][j] == cur)
                    {
                        for(int k=0;k<4;++k)
                        {
                            if(i + dirX[k] >= 1)
                            {
                                if(i + dirX[k] <= n)
                                {
                                    if(j + dirY[k] >= 1)
                                    {
                                        if(j + dirY[k] <= n)
                                        {
                                            if(!m[i+dirX[k]][j+dirY[k]])
                                            {
                                                m[i+dirX[k]][j+dirY[k]] = cur + 1;
                                                flag = true;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            ++ cur;
        }
        for(int i=1;i<=n;++i)
        {
            printf("%d", m[i][1] - 1);
            for(int j=2;j<=n;++j)
            {
                printf(" %d", m[i][j] - 1);
            }
            printf("\n");
        }
    }
    return 0;
}
