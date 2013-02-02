#include <cstdio>
#include <cstring>
#include <cmath>
static const int MAXN = 1001;
static const int MAXM = 5001;
static const double eps = 1e-3;

struct Edge
{
    int v, next;
    double w;
}edge[MAXM];
struct Node
{
    int u, v, w;
}node[MAXM];
int n, m, edgeNumber;
int fun[MAXN], head[MAXN], queue[MAXN], time[MAXN];
bool visited[MAXN];
double dist[MAXN];

void input()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&fun[i]);
    for(int i=1;i<=m;++i)
        scanf("%d%d%d",&node[i].u,&node[i].v,&node[i].w);
}

inline void addEdge(int u, int v, double w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next  = head[u];
    head[u] = edgeNumber++;
}

void makeGraph(double x)
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
    for(int i=1;i<=m;++i)
    {
        addEdge(node[i].u, node[i].v, fun[node[i].u] - x * node[i].w);
    }
}

bool spfa()
{
    for(int i=1;i<=n;++i)
    {
        visited[i] = true;
        dist[i] = 0.0;
        queue[i-1] = i;
        time[i] = 0;
    }
    int front = 0, rear = n;
    while(front != rear)
    {
        int u = queue[front];
        for(int i=head[u];i+1;i=edge[i].next)
        {
            if(dist[edge[i].v] < dist[u] + edge[i].w)
            {
                dist[edge[i].v] = dist[u] + edge[i].w;
                if(!visited[edge[i].v])
                {
                    visited[edge[i].v] = true;
                    if(++time[edge[i].v] > n)
                    {
                        return false;
                    }
                    queue[rear] = edge[i].v;
                    if(++rear >= MAXN)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visited[u] = false;
        if(++front >= MAXN)
        {
            front = 0;
        }
    }
    return true;
}

void solve()
{
    double left = 0.0, right = 50;
    double mid;
    while(right - left > eps)
    {
        mid = (left + right) * 0.5;
        makeGraph(mid);
        if(spfa())
            right = mid;
        else
            left = mid;
    }
    printf("%.2lf\n", left);
}

int main()
{
    input();
    solve();
    return 0;
}
