#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXC = 5010;
const int MAXN = 2010;
const int MAXM = 1010;

int c, n, k, m;
struct City
{
    int x, belong;
    inline void input()
    {
        scanf("%d%d",&x,&belong);
    }
    bool operator < (const City &city) const
    {
        return x < city.x;
    }
}city[MAXC];
int dp[MAXC][2];
bool visit[MAXN];
int inside[MAXN];
int ans;
struct Edge
{
    int v, next;
}edge[MAXM * 2];
int edgeNumber, head[MAXN];

inline void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(const int &u, const int &v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void dfs(int u)
{
    visit[u] = true;
    dp[u][0] = 0;
    dp[u][1] = 1;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        if(!visit[v] && inside[v])
        {
            dfs(v);
            dp[u][0] += max(dp[v][0], dp[v][1]);
            dp[u][1] += dp[v][0];
        }
    }
}

bool judge()
{
    memset(visit, false, sizeof(visit));
    int sum = 0;
    for(int i=1;i<=n;++i)
    {
        if(inside[i] && !visit[i])
        {
            dfs(i);
            sum += max(dp[i][0], dp[i][1]);
        }
    }
    return sum >= k;
}

void solve()
{
    int l = 0, r = 0;
    int countryNumber = 1;
    sort(city, city + c);
    memset(inside, 0, sizeof(inside));
    inside[city[0].belong] = 1;
    while(l < c && r < c)
    {
        bool flag = false;
        if(countryNumber >= k)
        {
            if(judge())
            {
                flag = true;
                if(ans == -1)
                {
                    ans = city[r].x - city[l].x;
                }
                else
                {
                    ans = min(ans, city[r].x - city[l].x);
                }
            }
        }
        if(flag)
        {
            -- inside[city[l].belong];
            if(inside[city[l].belong] == 0)
            {
                -- countryNumber;
            }
            ++ l;
        }
        else
        {
            ++ r;
            if(inside[city[r].belong] == 0)
            {
                ++ countryNumber;
            }
            ++ inside[city[r].belong];
        }
    }
}

int main()
{
    int caseNumber;
    int u, v;
    scanf("%d", &caseNumber);
    for(int cas=1;cas<=caseNumber;++cas)
    {
        scanf("%d%d%d%d",&c,&n,&k,&m);
        for(int i=0;i<c;++i)
        {
            city[i].input();
        }
        clearEdge();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d",&u,&v);
            addEdge(u, v);
            addEdge(v, u);
        }
        printf("Case #%d: ", cas);
        ans = -1;
        solve();
        printf("%d\n", ans);
    }
    return 0;
}
