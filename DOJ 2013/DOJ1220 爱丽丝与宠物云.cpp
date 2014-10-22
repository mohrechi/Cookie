#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 300 + 10;
const int MAXM = MAXN * MAXN;
const double HIT[4][4] =
{
    {0.0, 0.0, 0.0, 0.0},
    {0.0, 0.5, 0.5, 2.0},
    {0.0, 2.0, 0.5, 0.5},
    {0.0, 0.5, 2.0, 0.5}
};

int n;
struct Monster
{
    int G, F, HP, S;
    inline void input()
    {
        scanf("%d%d%d%d", &G, &F, &HP, &S);
    }
} monster[MAXN];

struct Edge
{
    int v, w, next;
} edge[MAXM];
int head[MAXN], edgeNum;

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w)
{
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

bool visit[MAXN];
int queue[MAXN];
int dist[MAXN];

int spfa(int s, int t)
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    memset(dist, -1, sizeof(dist));
    visit[s] = true;
    dist[s] = 0;
    queue[0] = s;
    while (front != rear)
    {
        int u = queue[front];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if (dist[v] == -1 || dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                if (!visit[v])
                {
                    visit[v] = true;
                    queue[rear] = v;
                    if (++rear >= MAXN)
                    {
                        rear = 0;
                    }
                }
            }
        }
        visit[u] = false;
        if (++front >= MAXN)
        {
            front = 0;
        }
    }
    return dist[t];
}

int getDist(int u, int v)
{
    int hp1 = monster[u].HP;
    int hp2 = monster[v].HP;
    while (true)
    {
        hp2 -= max(1, (int)((monster[u].G - monster[v].F) * HIT[monster[u].S][monster[v].S]));
        if (hp2 <= 0)
        {
            break;
        }
        hp1 -= max(1, (int)((monster[v].G - monster[u].F) * HIT[monster[v].S][monster[u].S]));
        if (hp1 <= 0)
        {
            break;
        }
    }
    if (hp1 <= 0)
    {
        return -1;
    }
    return 1;
}

int main()
{
    int T, q;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i <= n; ++i)
        {
            monster[i].input();
        }
        clearEdge();
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (i == j)
                {
                    continue;
                }
                int d = getDist(i, j);
                if (d > 0)
                {
                    addEdge(i, j, d);
                }
            }
        }
        scanf("%d", &q);
        printf("%d\n", spfa(n, q - 1));
    }
    return 0;
}
