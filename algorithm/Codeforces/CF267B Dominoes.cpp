#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int n, a[MAXN], b[MAXN];
int degree[MAXN], graph[MAXN][MAXN];
bool visit[MAXN];
int ansNum, ans[MAXN];

bool dfs(int x)
{
    for(int i = 0; i <= 6; ++ i)
    {
        if(graph[x][i])
        {
            -- graph[x][i];
            -- graph[i][x];
            dfs(i);
        }
    }
    ans[ansNum++] = x;
    return ansNum == n + 1;
}

int main()
{
    while(~scanf("%d", &n))
    {
        memset(graph, 0, sizeof(graph));
        memset(degree, 0, sizeof(degree));
        for(int i = 1; i <= n; ++ i)
        {
            scanf("%d%d", &a[i], &b[i]);
            ++ graph[a[i]][b[i]];
            ++ graph[b[i]][a[i]];
            ++ degree[a[i]];
            ++ degree[b[i]];
        }
        int start = a[1];
        int count = 0;
        for(int i = 0; i <= 6; ++ i)
        {
            if(degree[i] & 1)
            {
                start = i;
                ++ count;
            }
        }
        if(count > 2)
        {
            printf("No solution\n");
            continue;
        }
        ansNum = 0;
        memset(visit, false, sizeof(visit));
        if(dfs(start))
        {
            for(int i = 0; i < n; ++ i)
            {
                for(int j = 1; j <= n; ++ j)
                {
                    if(!visit[j])
                    {
                        if(ans[i] == a[j] && ans[i + 1] == b[j])
                        {
                            printf("%d +\n", j);
                            visit[j] = true;
                            break;
                        }
                        if(ans[i] == b[j] && ans[i + 1] == a[j])
                        {
                            printf("%d -\n", j);
                            visit[j] = true;
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            printf("No solution\n");
        }
    }
    return 0;
}
