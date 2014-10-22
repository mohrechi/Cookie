#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 30;
const int MAXM = MAXN * MAXN  * 4;
const long long INF = 0x7FFFFFFFFFFFFFFFLL;
int n;
long long a[MAXN], b[MAXN];

struct Edge
{
    int u, v, f, next;
    long long w;
} edge[MAXM];
int head[MAXM], edgeNumber;
int source, destination;

void initEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int f, long long w)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].f = f;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

inline void addEdge(int u, int v, int f, long long w)
{
    addEdgeSub(u, v, f, w);
    addEdgeSub(v, u, 0, -w);
}

void buildGraph()
{
    initEdge();
    source = 0;
    destination = n + n + 1;
    for(int i=1;i<=n;++i)
    {
        addEdge(source, i, 1, 0);
    }
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            if(a[i] >= b[j])
            {
                addEdge(i, j + n, 1, (a[i] - b[j]) * (a[i] - b[j]));
            }
            else
            {
                addEdge(i, j + n, 1, - (a[i] - b[j]) * (a[i] - b[j]));
            }
        }
    }
    for(int i=1;i<=n;++i)
    {
        addEdge(i + n, destination, 1, 0);
    }
}

int queue[MAXM];
int prev[MAXM];
bool visit[MAXM];
long long dist[MAXM];

bool spfa()
{
    for(int i=source;i<=destination;++i)
    {
        visit[i] = false;
        prev[i] = -1;
        dist[i] = - INF;
    }
    bool flag = false;
    int front = 0, rear = 1;
    queue[0] = source;
    dist[source] = 0;
    visit[source] = true;
    while(front != rear)
    {
        int u = queue[front];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            long long w = edge[i].w;
            if(edge[i].f && dist[v] < dist[u] + w)
            {
                prev[v] = i;
                dist[v] = dist[u] + w;
                if(!visit[v])
                {
                    visit[v] = true;
                    queue[rear] = v;
                    if(++ rear >= MAXM)
                    {
                        rear = 0;
                    }
                }
                if(v == destination)
                {
                    flag = true;;
                }
            }
        }
        visit[u] = false;
        if(++ front >= MAXM)
        {
            front = 0;
        }
    }
    return flag;
}

long long flow()
{
    long long ans = 0;
    int time = 0;
    while(spfa())
    {
        int temp = destination;
        int f = 0x7FFFFFFF;
        while(prev[temp] != -1)
        {
            f = min(f, edge[prev[temp]].f);
            temp = edge[prev[temp]].u;
        }
        temp = destination;
        while(prev[temp] != -1)
        {
            edge[prev[temp]].f -= f;
            edge[prev[temp]^1].f += f;
            temp = edge[prev[temp]].u;
        }
        ans += dist[destination];
    }
    return ans;
}

int main()
{
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%lld", &a[i]);
        }
        for(int i=1;i<=n;++i)
        {
            scanf("%lld", &b[i]);
        }
        buildGraph();
        printf("%lld\n", flow());
    }
    return 0;
}
