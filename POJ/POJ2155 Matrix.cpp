#include <cstdio>
#include <cstring>
const int MAXN = 1005;
bool c[MAXN][MAXN];
int n, m;

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int y)
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        for(int j=y;j<=n;j+=lowbit(j))
        {
            c[i][j] = !c[i][j];
        }
    }
}

bool query(int x, int y)
{
    bool ret = false;
    for(int i=x;i>0;i-=lowbit(i))
    {
        for(int j=y;j>0;j-=lowbit(j))
        {
            ret ^= c[i][j];
        }
    }
    return ret;
}

int main()
{
    int casNum, left, top, right, bottom;
    char op[10];
    scanf("%d", &casNum);
    for(int k=0;k<casNum;++k)
    {
        memset(c, 0, sizeof(c));
        scanf("%d%d", &n, &m);
        if(k)
        {
            printf("\n");
        }
        while(m--)
        {
            scanf("%s", op);
            if(*op == 'C')
            {
                scanf("%d%d%d%d",&left,&top,&right,&bottom);
                ++ right, ++ bottom;
                update(left, top);
                update(right, bottom);
                update(left, bottom);
                update(right, top);
            }
            else
            {
                scanf("%d%d",&left,&top);
                printf("%d\n", query(left, top));
            }
        }
    }
}
