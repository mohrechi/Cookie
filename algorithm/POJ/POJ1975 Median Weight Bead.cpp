#include <cstdio>
#include <cstring>
static const int MAXN = 100;
bool map[MAXN][MAXN];
int n, m, ans;

int main(int argc, char *argv[])
{
    int t, a, b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(map, false, sizeof(map));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            map[a][b] = true;
        }
        ans = 0;
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)
                    if(map[i][k] && map[k][j])
                        map[i][j] = true;
        int c1, c2, a = ((n+1)>>1);
        for(int i=1;i<=n;++i)
        {
            c1 = c2 = 0;
            for(int j=1;j<=n;++j)
            {
                if(map[i][j]) ++c1;
                if(map[j][i]) ++c2;
            }
            if(c1 >= a || c2 >= a) ++ ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}
