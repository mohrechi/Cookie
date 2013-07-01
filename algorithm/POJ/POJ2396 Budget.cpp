#include <iostream>
#include <cmath>
#include <stdio.h>
#include <memory.h>
using namespace std;
#define MAXN 300
#define INF 1000000000
int cap[MAXN][MAXN], low[MAXN][MAXN], up[MAXN][MAXN];
int st[MAXN],ed[MAXN];
int row[MAXN], col[MAXN];
int flow[MAXN][MAXN];
bool visit[MAXN];
int path[MAXN],queue[MAXN];

void init()
{
    memset(cap, 0, sizeof(cap));
    memset(low, 0, sizeof(low));
    memset(up, 0, sizeof(up));
    memset(st, 0, sizeof(st));
    memset(ed, 0, sizeof(ed));
    memset(flow, 0, sizeof(flow));
}

bool findPath(int s, int t, int n)
{
    memset(path, -1, sizeof(path));
    memset(visit, false, sizeof(visit));
    int front = 1, rear = 0;
    queue[0] = s;
    visit[s] = true;
    while(rear < front)
    {
        int r = queue[rear++];
        for(int i=0;i<n;i++)
        {
            if(cap[r][i] && !visit[i])
            {
                visit[i] = true;
                queue[front++] = i;
                path[i] = r;
                if(i==t)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int getFlow(int s, int t, int n)
{
    int res = 0;
    while(findPath(s, t, n))
    {
        int minFlow = INF;
        int x = t;
        while(path[x] != -1)
        {
            if(cap[path[x]][x] < minFlow)
            {
                minFlow = cap[path[x]][x];
            }
            x = path[x];
        }
        x = t;
        res += minFlow;
        while(path[x] != -1)
        {
            cap[path[x]][x] -= minFlow;
            cap[x][path[x]] += minFlow;
            flow[path[x]][x] += minFlow;
            flow[x][path[x]] -= minFlow;
            x = path[x];
        }
    }
    return res;
}

void solve(int s, int t, int n, int n1, int m1)
{
    int vs = n;
    int vt = n+1;
    int res = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cap[i][j] = up[i][j] - low[i][j];
            st[i] += low[i][j];
            ed[j] += low[i][j];
            res += low[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        cap[vs][i] = ed[i];
        cap[i][vt] = st[i];
    }
    cap[t][s] = INF;
    int ans = getFlow(vs, vt, n+2);
    if(ans != res)
    {
        printf("IMPOSSIBLE\n");
        return;
    }
    cap[t][s] = cap[s][t] = 0;
    getFlow(s, t, n);
    for(int i=1;i<=n1;i++)
    {
        printf("%d", flow[i][1+n1] + low[i][1+n1]);
        for(int j=2;j<=m1;j++)
        {
            printf(" %d", flow[i][j+n1] + low[i][j+n1]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        int n, m, k;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&row[i]);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&col[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                up[i][j+n] = INF;
            }
        }
        scanf("%d",&k);
        while(k--)
        {
            int x, y, z;
            char ch;
            scanf("%d %d %c %d",&x,&y,&ch,&z);
            if(x==0 && y!=0)
            {
                if(ch == '=')
                {
                    for(int i=1;i<=n;i++)
                    {
                        low[i][y+n] = z;
                        up[i][y+n] = z;
                    }
                }
                else if(ch == '>')
                {
                    for(int i=1;i<=n;i++)
                    {
                        low[i][y+n] = max(low[i][y+n], z+1);
                    }
                }
                else
                {
                    for(int i=1;i<=n;i++)
                    {
                        up[i][y+n] = min(up[i][y+n], z-1);
                    }
                }
            }
            else if(y==0 && x!=0)
            {
                if(ch == '=')
                {
                    for(int i=1;i<=m;i++)
                    {
                        low[x][i+n] = z;
                        up[x][i+n] = z;
                    }
                }
                else if(ch == '>')
                {
                    for(int i=1;i<=m;i++)
                    {
                        low[x][i+n] = max(low[x][i+n], z+1);
                    }
                }
                else
                {
                    for(int i=1;i<=m;i++)
                    {
                        up[x][i+n] = min(up[x][i+n], z-1);
                    }
                }
            }
            else if(x==0 && y==0)
            {
                for(int i=1;i<=n;i++)
                {
                    for(int j=1;j<=m;j++)
                    {
                        if(ch == '=')
                        {
                            low[i][j+n] = up[i][j+n] = z;
                        }
                        else if(ch == '>')
                        {
                            low[i][j+n] = max(low[i][j+n], z+1);
                        }
                        else
                        {
                            up[i][j+n] = min(up[i][j+n], z-1);
                        }
                    }
                }
            }
            else
            {
                if(ch == '=')
                {
                    up[x][y+n] = low[x][y+n] = z;
                }
                else if(ch == '>')
                {
                    low[x][y+n] = max(low[x][y+n], z+1);
                }
                else
                {
                    up[x][y+n] = min(up[x][y+n], z-1);
                }
            }
        }
        int s = 0, t = n+m+1;
        for(int i=1;i<=n;i++)
        {
            up[s][i] = low[s][i] = row[i];
        }
        for(int i=1;i<=m;i++)
        {
            up[i+n][t] = low[i+n][t] = col[i];
        }
        solve(s,t,n+m+2,n,m);
        if(t)
        {
            printf("\n");
        }
    }
    return 0;
}
