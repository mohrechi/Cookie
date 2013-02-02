#include <cstdio>
#include <cstring>
static const int MAXN = 300;
static const int INF = 1000000000;

struct Edge
{
    int to,flow,next;
}edge[MAXN*MAXN*2];
int edgeNumber;
int k, c, n, m;
int depth[MAXN], head[MAXN], dist[MAXN][MAXN];

int min(int x, int y)
{
    return x<y?x:y;
}

bool input()
{
    if(~scanf("%d%d%d",&k,&c,&m))
    {
        n = k + c;
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                scanf("%d",&dist[i][j]);
            }
        }
        return true;
    }
    return false;
}

void floyd()
{
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(dist[i][k] && dist[k][j] && (dist[i][j] == 0 || dist[i][j] > dist[i][k] + dist[k][j]))
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

void addEdgeSub(int from, int to, int flow)
{
    edge[edgeNumber].to = to;
    edge[edgeNumber].flow = flow;
    edge[edgeNumber].next = head[from];
    head[from] = edgeNumber++;
}

void addEdge(int from, int to, int flow)
{
    addEdgeSub(from, to, flow);
    addEdgeSub(to, from, 0);
}

void make(int mid)
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
    for(int i=1;i<=k;++i)
    {
        addEdge(0, i, m);
    }
    for(int i=k+1;i<=n;++i)
    {
        addEdge(i, n+1, 1);
    }
    for(int i=1;i<=k;++i)
    {
        for(int j=k+1;j<=n;++j)
        {
            if(dist[i][j] && dist[i][j] <= mid)
            {
                addEdge(i, j, 1);
            }
        }
    }
}

bool bfs(int start, int end)
{
    int front = 0, rear = 0;
    int queue[MAXN];
    memset(depth, -1, sizeof(depth));
    queue[front++] = start;
    depth[start] = 0;
    while(rear < front)
    {
        int k = queue[rear++];
        for(int i=head[k];i!=-1;i=edge[i].next)
        {
            int to = edge[i].to;
            if(-1 == depth[to] && edge[i].flow > 0)
            {
                depth[to] = depth[k] + 1;
                queue[front++] = to;
            }
        }
    }
    return -1 != depth[end];
}

int dinic(int start, int end, int sum)
{
    if(start == end)
    {
        return sum;
    }
    int temp = sum;
    for(int i=head[start];i!=-1 && sum;i=edge[i].next)
    {
        if(edge[i].flow > 0 && depth[edge[i].to] == depth[start] + 1)
        {
            int a = dinic(edge[i].to, end, min(sum, edge[i].flow));
            edge[i].flow -= a;
            edge[i^1].flow += a;
            sum -= a;
        }
    }
    return temp - sum;
}

int maxflow(int start, int end)
{
    int result = 0;
    while(bfs(start, end))
    {
        result += dinic(start, end, INF);
    }
    return result;
}


void solve()
{
    int ans = INF;
    int left = 1, right = 500 * n;
    int mid;
    while(left <= right)
    {
        mid = (left + right) >> 1;
        make(mid);
        if(maxflow(0, n+1) == c)
        {
            right = mid - 1;
            if(mid < ans)
            {
                ans = mid;
            }
        }
        else
        {
            left = mid + 1;
        }
    }
    printf("%d\n",ans);
}

int main(int argc, char *argv[])
{
    while(input())
    {
        floyd();
        solve();
    }
    return 0;
}
