#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
static const int MAXN = 105;

int t, n, p;
int g[MAXN][MAXN];
int d[MAXN*MAXN];
int dnum;

int main()
{
    scanf("%d", &t);
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%d%d",&p,&n);
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                scanf("%d", &g[i][j]);
        for(int k=0;k<n;++k)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    if(g[i][k] + 1)
                        if(g[k][j] + 1)
                            if(g[i][j] == -1 || g[i][j] > g[i][k] + g[k][j])
                                g[i][j] = g[i][k] + g[k][j];
        dnum = 0;
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                if(g[i][j]>0)
                    d[dnum++] = g[i][j];
        sort(d, d + dnum);
        int pos = ceil(n*(n-1)*p/100.0) - 1;
        printf("Scenario #%d:\n",cas);
        printf("%d\n\n",d[pos]);
    }
    return 0;
}
