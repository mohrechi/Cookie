#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
static const int MAXN = 1005;
static const int MAXM = 100005;
static const int INF = 1000000000;

struct Edge
{
    int v, w, next;
}edge[MAXM], redge[MAXM];
int edgeNumber, head[MAXN];
int redgeNumber, rhead[MAXN];
int n, m;
int s, t, k;
int ans;
int dist[MAXN];
bool visited[MAXN];

void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

void raddEdge(int u, int v, int w)
{
    redge[redgeNumber].v = v;
    redge[redgeNumber].w = w;
    redge[redgeNumber].next = rhead[u];
    rhead[u] = redgeNumber++;
}

void spfa()
{
    for(int i=1;i<=n;++i)
    {
        visited[i] = false;
        dist[i] = INF;
    }
    visited[t] = true;
    dist[t] = 0;
    queue<int> q;
    q.push(t);
    while(!q.empty())
    {
        int u = q.front();
        for(int i=rhead[u];i!=-1;i=redge[i].next)
        {
            int v = redge[i].v;
            if(dist[v] > dist[u] + redge[i].w)
            {
                dist[v] = dist[u] + redge[i].w;
                if(!visited[v])
                {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        q.pop();
        visited[u] = false;
    }
}

typedef struct Node
{
    int length, index;
}Node;

bool operator < (const Node &a, const Node &b)
{
    return a.length + dist[a.index] > b.length + dist[b.index];
}

bool solve()
{
    if(dist[s] == INF)
    {
        return false;
    }
    int ansNumber = 0;
    priority_queue<Node> q;
    Node u, v;
    u.length = 0;
    u.index = s;
    q.push(u);
    while(!q.empty())
    {
        u = q.top();
        q.pop();
        if(u.index == t)
        {
            if(++ansNumber == k)
            {
                ans = u.length;
                return true;
            }
        }
        for(int i=head[u.index];i!=-1;i=edge[i].next)
        {
            v.length = u.length + edge[i].w;
            v.index = edge[i].v;
            q.push(v);
        }
    }
    return false;
}

int main()
{
    int u, v, w;
    while(~scanf("%d%d", &n, &m))
    {
        memset(head, -1, sizeof(head));
        memset(rhead, -1, sizeof(rhead));
        edgeNumber = 0;
        redgeNumber = 0;
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            raddEdge(v, u, w);
        }
        scanf("%d%d%d", &s, &t, &k);
        if(s == t)
        {
            ++ k;
        }
        spfa();
        if(solve())
        {
            printf("%d\n", ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
