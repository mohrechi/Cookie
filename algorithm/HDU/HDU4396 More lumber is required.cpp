#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 5005;
const int MAXM = 200005;
const int MAXK = 505;
const int MAXQ = MAXN * MAXK;
const int INF = 1000000000;

struct Edge
{
    int v, w, next;
}edge[MAXM];
int edgeNumber, head[MAXN];
int n, m;
int s, t, k;
int ans;

inline void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

int queue[MAXQ][2];
bool visit[MAXN][MAXK];
int dist[MAXN][MAXK];

void solve()
{
    ans = -1;
    int front = 0, rear = 1;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=k;++j)
        {
            visit[i][j] = false;
            dist[i][j] = INF;
        }
    }
    queue[0][0] = s;
    queue[0][1] = 0;
    visit[s][0] = true;
    dist[s][0] = 0;
    while(front != rear)
    {
        int u = queue[front][0];
        int uk = queue[front][1];
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v = edge[i].v;
            int vk = uk + 10;
            int w = edge[i].w;
            if(vk > k)
            {
                vk = k;
            }
            if(dist[v][vk] > dist[u][uk] + w)
            {
                dist[v][vk] = dist[u][uk] + w;
                if(v == t && vk == k)
                {
                    ans = dist[v][vk];
                }
                if(!visit[v][vk])
                {
                    visit[v][vk] = true;
                    queue[rear][0] = v;
                    queue[rear][1] = vk;
                    if(++rear >= MAXQ)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visit[u][uk] = false;
        if(++front >= MAXQ)
        {
            front = 0;
        }
    }
}

int main()
{
    int u, v, w;
    while(~scanf("%d%d", &n, &m))
    {
        clearEdge();
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        scanf("%d%d%d", &s, &t, &k);
        solve();
        printf("%d\n", ans);
    }
    return 0;
}
