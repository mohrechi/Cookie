#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;
const int MAXM = MAXN * MAXN;
const int MAXF = 55;
const int INF = 0x3f3f3f3f;

struct Edge
{
    int v, next;
} edge[MAXM * 2];
int head[MAXN], edgeNum;
int n, m;
int s, t;
int x, y, f;
int c[MAXN];

inline void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

int front, rear;
bool visit[MAXN][MAXF][3];
int dist[MAXN][MAXF][3];
int qn[MAXN * MAXF * 3];
int qf[MAXN * MAXF * 3];
int qs[MAXN * MAXF * 3];

void addQueue(int v, int vf, int vs, int w)
{
    if (dist[v][vf][vs] > w)
    {
        dist[v][vf][vs] = w;
        if (!visit[v][vf][vs])
        {
            visit[v][vf][vs] = true;
            qn[rear] = v;
            qf[rear] = vf;
            qs[rear] = vs;
            if (++rear >= MAXN * MAXF * 3)
            {
                rear = 0;
            }
        }
    }
}

void spfa()
{
    front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist, 0x3f, sizeof(dist));
    visit[s][0][0] = true;
    dist[s][0][0] = 0;
    qn[0] = s;
    qf[0] = 0;
    qs[0] = 0;
    while (front != rear)
    {
        int u = qn[front];
        int uf = qf[front];
        int us = qs[front];
        int vf = uf;
        int vs = us;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            addQueue(v, vf, vs, dist[u][uf][us] + c[u]);
        }
        if ((u == x && us != 2) || (u == y && us != 1) || (u != x && u != y))
        {
            if (uf < f)
            {
                vf = uf + 1;
                vs = us;
                if (u == x)
                {
                    vs = 1;
                }
                else if (u == y)
                {
                    vs = 2;
                }
                for (int i = head[u]; i != -1; i = edge[i].next)
                {
                    int v = edge[i].v;
                    addQueue(v, vf, vs, dist[u][uf][us]);
                }
            }
        }
        visit[u][uf][us] = false;
        if (++front >= MAXN * MAXF * 3)
        {
            front = 0;
        }
    }
}

int main()
{
    int u, v;
    while (~scanf("%d%d", &n, &m))
    {
        clearEdge();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &c[i]);
        }
        scanf("%d%d", &s, &t);
        addEdge(t, 0);
        scanf("%d%d%d", &x, &y, &f);
        spfa();
        int ans = INF;
        for (int i = 0; i <= f; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                ans = min(ans, dist[0][i][j]);
            }
        }
        if (ans == INF)
        {
            ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
