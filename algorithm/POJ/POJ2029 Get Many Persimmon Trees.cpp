#define METHOD_DP
//#define METHOD_BIT
#include <cstdio>
#include <cstring>
static const int MAXN = 505;
int tree[MAXN][MAXN];
int n, h, w, x, y, a, b, m, t;

#if defined(METHOD_DP)
int main(int argc, char *argv[])
{
    while(scanf("%d",&n),n)
    {
        memset(tree, 0, sizeof(tree));
        scanf("%d%d",&h,&w);
        while(n--)
        {
            scanf("%d%d",&x,&y);
            tree[x][y] = 1;
        }
        for(int i=1;i<=h;++i)
        {
            for(int j=1;j<=w;++j)
            {
                tree[i][j] += tree[i-1][j] + tree[i][j-1] - tree[i-1][j-1];
            }
        }
        scanf("%d%d",&a,&b);
        m = 0;
        for(int i=a;i<=h;++i)
        {
            for(int j=b;j<=w;++j)
            {
                t = tree[i][j] - tree[i-a][j] - tree[i][j-b] + tree[i-a][j-b];
                if(t > m)
                {
                    m = t;
                }
            }
        }
        printf("%d\n", m);
    }
    return 0;
}
#endif

#if defined(METHOD_BIT)
void update(int x, int y)
{
    int y1;
    while(x <= h)
    {
        y1 = y;
        while(y1 <= w)
        {
            ++tree[x][y1];
            y1 += y1 & -y1;
        }
        x += x & -x;
    }
}

int sum(int x, int y)
{
    int res = 0;
    int y1;
    while(x > 0)
    {
        y1 = y;
        while(y1 > 0)
        {
            res += tree[x][y1];
            y1 -= y1 & -y1;
        }
        x -= x & -x;
    }
    return res;
}

int main(int argc, char *argv[])
{
    while(scanf("%d",&n),n)
    {
        scanf("%d%d",&h,&w);
        memset(tree, 0, sizeof(tree));
        for(int i=0;i<n;++i)
        {
            scanf("%d%d",&x,&y);
            update(x, y);
        }
        scanf("%d%d",&a,&b);
        m = 0;
        for(int i=a;i<=h;++i)
        {
            for(int j=b;j<=w;++j)
            {
                t = sum(i, j) - sum(i-a, j) - sum(i, j-b) + sum(i-a, j-b);
                if(t > m)
                {
                    m = t;
                }
            }
        }
        printf("%d\n", m);
    }
    return 0;
}
#endif
