#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000 + 10;

int n;
struct Planet
{
    int x, y, z, h;
} planet[MAXN];
int c, s;

struct Edge
{
    int v, w, next;
} edge[MAXN * MAXN * 2];
int head[MAXN], edgeNum;

bool visit[MAXN][6];
int dist[MAXN][6], qu[MAXN * 6], qs[MAXN * 6];

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v, int w)
{
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

inline void addEdge(int u, int v, int w)
{
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, w);
}

inline int getTime(int u, int v)
{
    return (max(max(abs(planet[u].x - planet[v].x), abs(planet[u].y - planet[v].y)), abs(planet[u].z - planet[v].z)) +
            min(min(abs(planet[u].x - planet[v].x), abs(planet[u].y - planet[v].y)), abs(planet[u].z - planet[v].z)) + 1) >> 1;
}

inline int getEnergy(int u, int v)
{
    return abs(planet[u].x - planet[v].x) + abs(planet[u].y - planet[v].y) + abs(planet[u].z - planet[v].z);
}

int spfa(int start, int end)
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    visit[start][s] = true;
    dist[start][s] = 0;
    qu[0] = start;
    qs[0] = s;
    int full = s;
    int ans = -1;
    while (front != rear)
    {
        int u = qu[front];
        int s = qs[front];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            int next = planet[v].h ? full : s - 1;
            if (next >= 0)
            {
                if (dist[v][next] == -1 || dist[v][next] > dist[u][s] + w)
                {
                    dist[v][next] = dist[u][s] + w;
                    if (v == end)
                    {
                        if (ans == -1 || ans > dist[v][next])
                        {
                            ans = dist[v][next];
                        }
                    }
                    if (!visit[v][next])
                    {
                        visit[v][next] = true;
                        qu[rear] = v;
                        qs[rear] = next;
                        if (++rear >= MAXN * 6)
                        {
                            rear = 0;
                        }
                    }
                }
            }
        }
        visit[u][s] = false;
        if (++front >= MAXN * 6)
        {
            front = 0;
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        planet[0].x = planet[0].y = planet[0].z = planet[0].h = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d%d%d", &planet[i].x, &planet[i].y, &planet[i].z, &planet[i].h);
        }
        scanf("%d%d", &c, &s);
        scanf("%d%d%d", &planet[n + 1].x, &planet[n + 1].y, &planet[n + 1].z);
        planet[n + 1].h = 0;
        clearEdge();
        for (int i = 0; i <= n + 1; ++i)
        {
            for (int j = i + 1; j <= n + 1; ++j)
            {
                if (getEnergy(i, j) <= c)
                {
                    addEdge(i, j, getTime(i, j));
                }
            }
        }
        printf("%d\n", spfa(0, n + 1));
    }
    return 0;
}
