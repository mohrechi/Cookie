#include <cstdio>
#include <cstring>
const int MAXN = 31;

int ans[MAXN][8];

int main()
{
    int n;
    ans[0][7] = 1;
    ans[1][0] = ans[1][3] = ans[1][6] = 1;
    for(int i=2;i<MAXN;++i)
    {
        for(int j=0;j<8;++j)
        {
            int s = (~j) & 7;
            ans[i][s] += ans[i-1][j];
            if(s == 0 || s == 4)
            {
                ans[i][s|3] += ans[i-1][j];
            }
            if(s == 0 || s == 1)
            {
                ans[i][s|6] += ans[i-1][j];
            }
        }
    }
    while(scanf("%d", &n), n+1)
    {
        printf("%d\n", ans[n][7]);
    }
    return 0;
}
