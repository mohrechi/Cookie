#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 310;
const int INF = 1000000000;

int n;
int queue[MAXN];
int c[MAXN][MAXN];
int dist[MAXN];
bool visit[MAXN];

void spfa(int start)
{
    int front = 0, rear = 0;
    for(int v=1;v<=n;++v)
    {
        if(v == start)
        {
            dist[v] = INF;
            visit[v] = false;
        }
        else
        {
            dist[v] = c[start][v];
            visit[v] = true;
            queue[rear++] = v;
        }
    }
    while(front != rear)
    {
        int u = queue[front];
        for(int v=1;v<=n;++v)
        {
            if(dist[v] > dist[u] + c[u][v])
            {
                dist[v] = dist[u] + c[u][v];
                if(!visit[v])
                {
                    visit[v] = true;
                    queue[rear] = v;
                    if(++rear >= MAXN)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visit[u] = false;
        if(++front >= MAXN)
        {
            front = 0;
        }
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                scanf("%d", &c[i][j]);
            }
        }
        spfa(1);
        int ans = dist[n];
        int loop = dist[1];
        spfa(n);
        ans = min(ans, loop + dist[n]);
        printf("%d\n", ans);
    }
    return 0;
}
