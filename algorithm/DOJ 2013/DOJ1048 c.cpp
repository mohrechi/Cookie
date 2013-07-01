#include <cstdio>
#include <cstring>
const int MAXN = 105;
const int MAXM = MAXN * MAXN;
int n;
long long ans;
bool graph[MAXN][MAXN];
long long value[MAXN];
bool visit[MAXN][MAXN];
long long dist[MAXN][MAXN];
int queue[MAXM];
int layer[MAXM];

inline long long cube(long long x)
{
    return x * x * x;
}

void spfa()
{
    memset(visit, false, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    visit[0][1] = true;
    dist[0][1] = 0;
    queue[0] = 0;
    layer[0] = 1;
    int front = 0, rear = 1;
    while(rear != front)
    {
        int u = queue[front];
        int l = layer[front];
        for(int i=0;i<=n+1 && l<=n+1;++i)
        {
            if(graph[u][i])
            {
                if(dist[i][l+1] == -1 || dist[i][l+1] > dist[u][l] + value[i] * (cube(l+1) - cube(l)))
                {
                    dist[i][l+1] = dist[u][l] + value[i] * (cube(l+1) - cube(l));
                    if(!visit[i][l+1])
                    {
                        visit[i][l+1] = true;
                        queue[rear] = i;
                        layer[rear] = l + 1;
                        if(++rear >= MAXM)
                        {
                            rear = 0;
                        }
                    }
                    if(i == n + 1)
                    {
                        if(ans == -1 || ans > dist[i][l+1])
                        {
                            ans = dist[i][l+1];
                        }
                    }
                }
            }
        }
        visit[u][l] = false;
        if(++ front >= MAXM)
        {
            front = 0;
        }
    }
}

int main()
{
    while(~scanf("%d", &n))
    {
        memset(graph, true, sizeof(graph));
        for(int i=0;i<=n+1;++i)
        {
            graph[i][i] = false;
            int k, j;
            scanf("%d", &k);
            while(k--)
            {
                scanf("%d", &j);
                graph[i][j] = false;
            }
        }
        for(int i=1;i<=n;++i)
        {
            scanf("%lld", &value[i]);
        }
        ans = -1;
        spfa();
        printf("%lld\n", ans);
    }
    return 0;
}
