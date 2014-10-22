#include <cstdio>
#include <cstring>
const int MAXN = 205;
const int MAXL = 20;

int n, d;
char str[MAXN][MAXL];
int len[MAXN];
int dp[MAXL][MAXL];

inline int min(int x, int y)
{
    return x < y ? x : y;
}

inline int min(int x, int y, int z)
{
    return min(x, min(y, z));
}

int distance(int a, int b)
{
    for(int i=0;i<MAXL;++i)
    {
        dp[i][0] = i;
        dp[0][i] = i;
    }
    for(int i=1;i<=len[a];++i)
    {
        for(int j=1;j<=len[b];++j)
        {
            if(str[a][i] == str[b][j])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                if(str[a][i] == str[b][j-1] && str[a][i-1] == str[b][j])
                {
                    dp[i][j] = min(dp[i][j], dp[i-2][j-2] + 1);
                }
                for(int k=2;k<=i-1;++k)
                {
                    if(str[a][i-k] == str[b][j] && str[a][i] == str[b][j-1])
                    {
                        dp[i][j] = min(dp[i][j], dp[i-k-1][j-k] + k);
                    }
                }
                for(int k=2;k<=j-1;++k)
                {
                    if(str[a][i] == str[b][j-k] && str[a][i-1] == str[b][j])
                    {
                        dp[i][j] = min(dp[i][j], dp[i-k][j-k-1] + k);
                    }
                }
            }
        }
    }
    return dp[len[a]][len[b]];
}

int main()
{
    char temp[MAXL];
    while(scanf("%d", &n), n)
    {
        scanf("%d", &d);
        for(int i=0;i<n;++i)
        {
            scanf("%s", str[i] + 1);
            for(int j=0;j<i;++j)
            {
                if(strcmp(str[i] + 1, str[j] + 1) < 0)
                {
                    strcpy(temp, str[i]+1);
                    strcpy(str[i]+1, str[j]+1);
                    strcpy(str[j]+1, temp);
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            len[i] = strlen(str[i] + 1);
        }
        int cnt = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=i+1;j<n;++j)
            {
                if(distance(i, j) <= d)
                {
                    printf("%s,%s\n", str[i] + 1, str[j] + 1);
                    ++ cnt;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
