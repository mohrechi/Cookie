#include <cstdio>
#include <cstring>
static const int MAXN = 300;
static const int MAXM = 15000;
static const int INF = 1000000000;

struct Edge
{
    int u, v, next;
    int cap, flow;
}edge[MAXM];
int edgeNumber, n, m, s, t;
int head[MAXN], level[MAXN], queue[MAXN];
int stack[MAXN], pre[MAXN];
bool visited[MAXN];

inline void addEdgeSub(int u, int v, int w)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].flow = 0;
    edge[edgeNumber].cap = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

inline void addEdge(int u, int v, int w)
{
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, 0);
}

inline bool bfs()
{
    memset(level, -1, sizeof(level));
    int front = 0, rear = 1;
    queue[0] = 0;
    level[0] = 0;
    while(front < rear)
    {
        int u = queue[front++];
        for(int i = head[u];i+1;i=edge[i].next)
        {
            if(level[edge[i].v] == -1 && edge[i].cap > edge[i].flow)
            {
                level[edge[i].v] = level[u] + 1;
                queue[rear++] = edge[i].v;
            }
        }
    }
    return level[t] >= 0;
}

inline int dfs()
{
    int top = 0;
    int ret = 0, cur, ptr, minf;
    int visitv[MAXN];
    memset(visited, false, sizeof(visited));
    stack[top++] = 0;
    pre[0] = 0;
    cur = 0;
    while(top)
    {
        while(cur != t && top)
        {
            int i;
            for(i=head[cur];i+1;i=edge[i].next)
            {
                if(level[edge[i].v]==level[cur] + 1 && edge[i].cap > edge[i].flow && !visited[edge[i].v])
                {
                    stack[top++] = edge[i].v;
                    cur = edge[i].v;
                    pre[edge[i].v] = i;
                    break;
                }
            }
            if(i == -1)
            {
                visited[cur] = 1;
                top--;
                if(top) cur = stack[top-1];
            }
        }
        if(cur == t)
        {
            minf = INF;
            while(cur != 0)
            {
                cur = pre[cur];
                if(edge[cur].cap - edge[cur].flow < minf)
                {
                    minf = edge[cur].cap - edge[cur].flow;
                }
                cur = edge[cur].u;
            }
            cur = t;
            while(cur != 0)
            {
                cur = pre[cur];
                edge[cur].flow += minf;
                edge[cur^1].flow -= minf;
                if(edge[cur].cap - edge[cur].flow == 0)
                {
                     ptr = edge[cur].u;
                }
                cur = edge[cur].u;
            }
            while(top > 0 && stack[top-1] != ptr)
            {
                --top;
            }
            if(top)
            {
                cur = stack[top-1];
            }
            ret += minf;
        }
    }
    return ret;
}

int dinic()
{
    int ret = 0, a;
    while(bfs())
    {
        a = dfs();
        if(a)
        {
            ret += a;
        }
        else
        {
            break;
        }
    }
    return ret;
}

void dfs(int x)
{
    visited[x] = true;
    for(int i=head[x];i+1;i=edge[i].next)
    {
        if(!visited[edge[i].v] && edge[i].cap > edge[i].flow)
        {
            dfs(edge[i].v);
        }
    }
}

int main()
{
    int u,v,w;
    scanf("%d%d",&n,&m);
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
    s = 0, t = n + n + 1;
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&w);
        addEdge(i+n, t, w);
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&w);
        addEdge(0, i, w);
    }
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&u,&v);
        addEdge(u, v+n, INF);
    }
    int ans = dinic();
    memset(visited, false, sizeof(visited));
    dfs(0);
    int num = 0;
    for(int i=1;i<=n;++i)
    {
        if(visited[i+n])
        {
            ++num;
        }
        if(!visited[i])
        {
            ++num;
        }
    }
    printf("%d\n%d\n",ans,num);
    for(int i=1;i<=n;++i)
    {
        if(visited[i+n])
        {
            printf("%d +\n",i);
        }
        if(!visited[i])
        {
            printf("%d -\n", i);
        }
    }
    return 0;
}
