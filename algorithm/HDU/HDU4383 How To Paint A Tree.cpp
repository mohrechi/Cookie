#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int INF = 1000000000;
const int step1[2][2][2] =
{
    0, 1, 1, 1,
    1, 1, 1, 0
};
const int step2[2][2][2][2] =
{
    0, 1, 1, 2, 1, 2, 2, 1,
    1, 2, 2, 1, 2, 1, 1, 0
};
const int reverse1[2][2] =
{
    0, 1, 1, 1
};
const int reverse2[2][2][2] =
{
    0, 1, 1, 1,
    1, 1, 1, 1
};
const int one1[2][2] =
{
    0, 0, 1, 0
};
const int one2[2][2][2] =
{
    0, 0, 0, -1,
    1, 0, 0, INF
};

int n;
int color[MAXN];
int dp[MAXN][2][2];
struct Edge
{
    int v, next;
} edge[MAXN * 2];
int edgeNumber, head[MAXN];

inline void initEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void input()
{
    int u, v;
    initEdge();
    for(int i=1; i<n; ++i)
    {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &color[i]);
    }
}

void dfs(int u, int father)
{
    int L = -1, R = -1;
    int a = color[u];
    int b = 1 - a;
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        if(edge[i].v != father)
        {
            if(L == -1)
            {
                L = edge[i].v;
            }
            else
            {
                R = edge[i].v;
            }
        }
    }
    if(L != -1)
    {
        dfs(L, u);
    }
    if(R != -1)
    {
        dfs(R, u);
    }
    dp[u][0][0] = dp[u][0][1] = INF;
    dp[u][1][0] = dp[u][1][1] = INF;
    if(L == -1 && R == -1)
    {
        dp[u][a][0] = 0;
        dp[u][a][1] = 2;
        dp[u][b][0] = 1;
        dp[u][b][1] = 1;
    }
    else if(R == -1)
    {
        for(int i1=0;i1<2;++i1)
        {
            for(int j1=0;j1<2;++j1)
            {
                for(int i2=0;i2<2;++i2)
                {
                    for(int j2=0;j2<2;++j2)
                    {
                        dp[u][i1][j1] = min(dp[u][i1][j1], dp[L][i2][j2] + step1[i1][color[u]^reverse1[j1][j2]][i2] + one1[j1][j2]);
                    }
                }
            }
        }
    }
    else
    {
        int op, fc;
        for(int i1=0;i1<2;++i1)
        {
            for(int j1=0;j1<2;++j1)
            {
                for(int i2=0;i2<2;++i2)
                {
                    for(int j2=0;j2<2;++j2)
                    {
                        for(int i3=0;i3<2;++i3)
                        {
                            for(int j3=0;j3<2;++j3)
                            {
                                dp[u][i1][j1] = min(dp[u][i1][j1], dp[L][i2][j2] + dp[R][i3][j3] + step2[i1][color[u]^reverse2[j1][j2][j3]][i2][i3] + one2[j1][j2][j3]);
                            }
                        }
                    }
                }
            }
        }
    }
}

void test()
{
    printf("DP: \n");
    for(int i=1;i<=n;++i)
    {
        printf("%2d: %d %d %d %d\n", i, dp[i][0][0], dp[i][0][1], dp[i][1][0], dp[i][1][1]);
    }
    printf("\n");
}

int main()
{
    int caseNumber = 0;
    while(~scanf("%d", &n))
    {
        input();
        dfs(1, -1);
        int ans = min(dp[1][0][0], dp[1][1][0]);
        #ifndef ONLINE_JUDGE
            test();
        #endif
        printf("Case %d: %d\n", ++caseNumber, ans);
    }
    return 0;
}
