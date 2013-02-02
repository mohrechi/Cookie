#include <cstdio>
#include <cstring>
const int MAXN = 100;
const int MAXM = MAXN * MAXN * 2;
const int INF = 1000000000;

int n, m, k;
int b[MAXN], sumB;
int c[MAXN][MAXN];
int source, destination;

struct Edge
{
    int u, v, w, f, next;
}edge[MAXM];
int edgeNumber, head[MAXN];

inline void initEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w, int f)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].f = f;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

inline void addEdge(int u, int v, int w, int f)
{
    addEdgeSub(u, v, w, f);
    addEdgeSub(v, u, -w, 0);
}

void buildGraph()
{
    initEdge();
    source = 0;
    destination = m + n + 1;
    for(int i=0;i<n;++i)
    {
        addEdge(source, i+1, 0, 1);
    }
    for(int i=0;i<m;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(c[i][j])
            {
                addEdge(j+1, i+n+1, 0, 1);
            }
        }
        addEdge(i+n+1, destination, k, b[i] / k);
        if(b[i] % k > 1)
        {
            addEdge(i+n+1, destination, b[i] % k, 1);
        }
    }
}

int dist[MAXN];
int queue[MAXN];
bool visit[MAXN];
int back[MAXN];

bool bfs()
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    queue[0] = source;
    dist[source] = 0;
    visit[source] = true;
    back[source] = - 1;
    bool flag = false;
    while(front != rear)
    {
        int u = queue[front];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if(edge[i].f)
            {

                if(dist[v] < dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    back[v] = i;
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
        }
        visit[u] = false;
        if(++front >= MAXN)
        {
            front = 0;
        }
    }
    return dist[destination] != -1;
}

int getFlow()
{
    int temp = destination;
    int min = INF;
    while(back[temp] != -1)
    {
        if(edge[back[temp]].f < min)
        {
            min = edge[back[temp]].f;
        }
        temp = edge[back[temp]].u;
    }
    temp = destination;
    while(back[temp] != -1)
    {
        edge[back[temp]].f -= min;
        edge[back[temp]^1].f += min;
        temp = edge[back[temp]].u;
    }
    return min;
}

bool judge()
{
    int cost = 0, flow = 0;
    while(bfs())
    {
        cost += dist[destination];
        flow += getFlow();
    }
    return n - flow >= sumB - cost;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int cas=1;cas<=t;++cas)
    {
        scanf("%d%d%d",&n,&m,&k);
        sumB = 0;
        for(int i=0;i<m;++i)
        {
            scanf("%d", &b[i]);
            sumB += b[i];
        }
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                scanf("%d", &c[i][j]);
            }
        }
        buildGraph();
        printf("Case #%d: ", cas);
        if(judge())
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
