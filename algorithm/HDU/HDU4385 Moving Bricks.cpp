#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 22;
const int INF = 1000000000;

struct Point
{
    int x, y;
    inline void input()
    {
        scanf("%d%d",&x,&y);
    }
}brick[MAXN];

int n;
int dist[MAXN][MAXN];
int dp[1<<MAXN];
int status[1<<MAXN];
int pre[1<<MAXN];

inline int getDist(const Point &a, const Point &b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

inline void getDist()
{
    for(int i=0;i<n;++i)
    {
        dist[i][i] = 0;
        for(int j=i+1;j<n;++j)
        {
            dist[i][j] = dist[j][i] = getDist(brick[i], brick[j]);
        }
    }
}

void solve()
{
    for(int i=0;i<(1<<n);++i)
    {
        dp[i] = INF;
        status[i] = 0;
    }
    dp[1] = 0;
    pre[1] = -1;
    int front = 0, rear = 1;
    for(int u=1;u<(1<<n);++u)
    {
        for(int i=1;i<n;++i)
        {
            if((u & (1 << i)) == 0)
            {
                int a = u | (1 << i);
                if(dp[a] > dp[u] + dist[0][i] + dist[i][0])
                {
                    dp[a] = dp[u] + dist[0][i] + dist[i][0];
                    status[a] = (1 << i);
                    pre[a] = u;
                }
                for(int j=1;j<n;++j)
                {
                    if((a & (1 << j)) == 0)
                    {
                        int b = a | (1 << j);
                        if(dp[b] > dp[u] + dist[0][i] + dist[i][j] + dist[j][0])
                        {
                            dp[b] = dp[u] + dist[0][i] + dist[i][j] + dist[j][0];
                            status[b] = (1 << i) | (1 << j);
                            pre[b] = u;
                        }
                    }
                }
            }
        }
    }
}

void output()
{
    int ans[MAXN], p;
    bool visit[MAXN];
    memset(visit, false, sizeof(visit));
    int t = (1 << n) - 1;
    while(t != -1)
    {
        for(int i=1;i<n;++i)
        {
            if(status[t] & (1 << i))
            {
                ans[i] = status[t];
            }
        }
        t = pre[t];
    }
    printf("%d\n", dp[(1<<n)-1]);
    for(int i=1;i<n;++i)
    {
        if(!visit[i])
        {
            for(int j=1;j<n;++j)
            {
                if(ans[i] & (1<<j))
                {
                    if(visit[0])
                    {
                        printf(" ");
                    }
                    else
                    {
                        visit[0] = true;
                    }
                    printf("%d", j);
                    visit[j] = true;
                }
            }
        }
    }
    printf("\n");
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        brick[0].input();
        scanf("%d", &n);
        for(int i=1;i<=n;++i)
        {
            brick[i].input();
        }
        ++ n;
        getDist();
        printf("Case %d:\n", cas);
        solve();
        output();
    }
    return 0;
}
