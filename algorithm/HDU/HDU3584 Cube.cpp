#include <cstdio>
#include <cstring>
const int MAXN = 105;

bool c[MAXN][MAXN][MAXN];
int n, m;

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int y, int z)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        for(int j=y;j<=n;j+=lowbit(j))
        {
            for(int k=z;k<=n;k+=lowbit(k))
            {
                c[i][j][k] = !c[i][j][k];
            }
        }
    }
}

bool query(int x, int y, int z)
{
    bool ret = false;
    for(int i=x;i>0;i-=lowbit(i))
    {
        for(int j=y;j>0;j-=lowbit(j))
        {
            for(int k=z;k>0;k-=lowbit(k))
            {
                ret ^= c[i][j][k];
            }
        }
    }
    return ret;
}

int main()
{
    int x[2], y[2], z[2];
    int op;
    while(~scanf("%d%d", &n, &m))
    {
        memset(c, false, sizeof(c));
        while(m--)
        {
            scanf("%d", &op);
            if(op)
            {
                for(int i=0;i<2;++i)
                {
                    scanf("%d%d%d", &x[i], &y[i], &z[i]);
                }
                ++ x[1], ++ y[1], ++ z[1];
                for(int i=0;i<2;++i)
                {
                    for(int j=0;j<2;++j)
                    {
                        for(int k=0;k<2;++k)
                        {
                            update(x[i], y[j], z[k]);
                        }
                    }
                }
            }
            else
            {
                scanf("%d%d%d", &x[0], &y[0], &z[0]);
                printf("%d\n", query(x[0], y[0], z[0]));
            }
        }
    }
    return 0;
}
