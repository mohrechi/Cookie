#include <cstdio>
#include <cstring>
const int MAXN = 15;
const int MAXM = 25;
const int INF = 1000000000;

int n, m, a[MAXN];
int c[MAXM], dp[MAXM][1<<MAXN];
int num[1<<MAXN];
bool isEven[1<<MAXN];

inline int min(int x, int y)
{
    return x < y ? x : y;
}

inline int getOneNumber(int x)
{
    int result = 0;
    while(x)
    {
        result += x & 1;
        x >>= 1;
    }
    return result;
}

void init()
{
    for(int i=0;i<(1<<MAXN);++i)
    {
        num[i] = getOneNumber(i);
        isEven[i] = ((num[i] & 1) == 0);
    }
}

int main()
{
    init();
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
        }
        if(n == 1)
        {
            if(a[0])
            {
                printf("impossible\n");
            }
            else
            {
                printf("0\n");
            }
        }
        else
        {
            memset(c, 0, sizeof(c));
            for(int i=1;i<MAXM;++i)
            {
                for(int j=0;j<n;++j)
                {
                    if(a[j] & (1 << (i - 1)))
                    {
                        c[i] |= (1 << j);
                    }
                    if(c[i])
                    {
                        m = i + 1;
                    }
                }
            }
            for(int i=0;i<=m;++i)
            {
                for(int j=0;j<(1<<n);++j)
                {
                    dp[i][j] = INF;
                }
            }
            dp[0][0] = 0;
            for(int i=1;i<=m;++i)
            {
                for(int j=0;j<(1<<n);++j)
                {
                    for(int k=0;k<(1<<n);++k)
                    {
                        if(dp[i-1][k] != INF)
                        {
                            if((j | (c[i] & k)) == j)
                            {
                                if(isEven[(~j) & (c[i] ^ k)] || j || num[(c[i] ^ k) | j] < n)
                                {
                                    dp[i][j] = min(dp[i][j], dp[i-1][k] + (!isEven[(~j) & (c[i] ^ k)] + num[j & (c[i] ^ k)] + ((num[j ^ (j & (c[i] ^ k))] - num[c[i] & k]) << 1)) * (1 << (i-1)));
                                }
                            }
                        }
                    }
                }
            }
            int ans = INF;
            for(int i=0;i<(1<<n);++i)
            {
                if(isEven[i])
                {
                    ans = min(ans, dp[m][i]);
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
