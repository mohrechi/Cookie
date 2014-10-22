#include <cstdio>

inline int max(int x, int y)
{
    return x>y?x:y;
}

int main()
{
    int n, a, dp[2][2][2], p, q;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",&a);
        if(i)
        {
            p = (i&1)>0;
            q = !p;
            dp[p][0][0] = max(dp[q][0][0], dp[q][1][1]);
            dp[p][1][0] = max(dp[q][1][0], dp[q][0][1]);
            dp[p][0][1] = max(dp[q][0][0], dp[q][1][1]) - a;
            dp[p][1][1] = max(dp[q][1][0], dp[q][0][1]) + a;
        }
        else
        {
            dp[0][0][0] = 0;
            dp[0][1][0] = 0;
            dp[0][0][1] = 0;
            dp[0][1][1] = a;
        }
    }
    p = (n&1)==0;
    printf("%d\n",max(max(dp[p][0][0], dp[p][0][1]), max(dp[p][1][0], dp[p][1][1])));
    return 0;
}
