#include <cstdio>
#include <cstring>
const int MAXN = 1505;

int dp[15][15];
char magic[MAXN][15];
int len[MAXN];
char temp[15];

inline int min(const int &x, const int &y)
{
    return x < y ? x : y;
}

inline int min(const int &x, const int &y, const int &z)
{
    return min(x, min(y, z));
}

int main()
{
    int t, n, m;
    scanf("%d", &t);
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;++i)
        {
            scanf("%s", magic[i]);
            len[i] = strlen(magic[i]);
        }
        printf("Case #%d:\n", cas);
        int threshold;
        for(int i=0;i<m;++i)
        {
            scanf("%s%d", temp, &threshold);
            int ans = 0;
            int l = strlen(temp);
            for(int j=0;j<n;++j)
            {
                for(int k=0;k<=l;++k)
                {
                    dp[0][k] = k;
                }
                for(int k=0;k<=len[j];++k)
                {
                    dp[k][0] = k;
                }
                for(int ii=0;ii<len[j];++ii)
                {
                    for(int jj=0;jj<l;++jj)
                    {
                        dp[ii+1][jj+1] = min(dp[ii][jj+1] + 1, dp[ii+1][jj] + 1, dp[ii][jj] + (magic[j][ii] == temp[jj] ? 0 : 1));
                    }
                }
                if(dp[len[j]][l] <= threshold)
                {
                    ++ ans;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
