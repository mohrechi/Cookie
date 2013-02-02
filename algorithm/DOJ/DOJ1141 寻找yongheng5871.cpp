#include <cstdio>
#include <cstring>
static const int MAXN = 200100;

int length;
char source[MAXN];
char temp[MAXN];
char target[] = " yongheng5871";
int dp[MAXN][15];
int from[MAXN][15];

inline int min(int x, int y)
{
    return x<y?x:y;
}

inline int min(int x, int y, int z)
{
    return min(x, min(y, z));
}

int main()
{
    while(~scanf("%s", source+1))
    {
        int m = 1000000000;
        length = strlen(source+1);
        if(length >= 6)
        {
            strcpy(temp, source+1);
            strcat(source+1, temp);
            length *= 2;
            for(int i=0;i<=length;i++)
                dp[i][0] = 0;
            for(int j=0;j<=12;j++)
                dp[0][j] = j;
            for(int i=1;i<=length;++i)
            {
                for(int j=1;j<=12;++j)
                {
                    if(source[i] == target[j])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = min(dp[i][j-1] + 1,
                                       dp[i-1][j] + 1,
                                       dp[i-1][j-1] + 1);
                    }
                }
                if(dp[i][12] < m)
                {
                    m = dp[i][12];
                }
            }
        }
        else
        {
            for(int k=0;k<12;++k)
            {
                for(int i=0;i<=length;i++)
                dp[i][0] = 0;
                for(int j=0;j<=12;j++)
                    dp[0][j] = j;
                for(int i=1;i<=length;++i)
                {
                    for(int j=1;j<=12;++j)
                    {
                        if(source[i] == target[j])
                        {
                            dp[i][j] = dp[i-1][j-1];
                        }
                        else
                        {
                            dp[i][j] = min(dp[i][j-1] + 1,
                                           dp[i-1][j] + 1,
                                           dp[i-1][j-1] + 1);
                        }
                    }
                    if(dp[i][12] < m)
                    {
                        m = dp[i][12];
                    }
                }
                for(int i=0;i<12;++i)
                {
                    target[i] = target[i+1];
                }
                target[12] = target[0];
            }
        }
        printf("%d\n", m);
    }
}
