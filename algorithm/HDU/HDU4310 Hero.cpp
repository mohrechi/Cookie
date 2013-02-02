#include <cstdio>
#include <cstring>
const int MAXN = 21;
const int MAXM = 1<<MAXN;
const int INF = 0x7fffffff;

int n, m;
__int64 hp[MAXN], dps[MAXN];
__int64 dp[MAXM];
__int64 totalDps[MAXM];
int queue[MAXM];
bool visit[MAXM];

inline int min(int x, int y)
{
    return x < y ? x : y;
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%I64d%I64d", &dps[i], &hp[i]);
        }
        m = 1<<n;
        for(int i=1;i<m;++i)
        {
            dp[i] = INF;
        }
        dp[0] = 0;
        memset(totalDps, 0, sizeof(totalDps));
        memset(visit, false, sizeof(visit));
        visit[0] = true;
        queue[0] = 0;
        int front = 0, rear = 1;
        while(front != rear)
        {
            int i = queue[front];
            for(int j=0;j<n;++j)
            {
                if(!(i & (1<<j)))
                {
                    int t = i|(1<<j);
                    totalDps[t] = totalDps[i] + dps[j];
                    if(dp[t] > dp[i] + hp[j] * totalDps[t])
                    {
                        dp[t] = dp[i] + hp[j] * totalDps[t];
                        if(!visit[t])
                        {
                            visit[t] = true;
                            queue[rear] = t;
                            if(++ rear >= MAXM)
                            {
                                rear = 0;
                            }
                        }
                    }
                }
            }
            visit[i] = false;
            if(++ front >= MAXM)
            {
                front = 0;
            }
        }
        printf("%I64d\n", dp[m-1]);
    }
    return 0;
}
