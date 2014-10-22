#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXP = 43;
const int MAXN = MAXP * 2 + 2;
const int MAXS = 6;

int T, s, p;
struct Edge
{
    int v, w, next;
} edge[MAXN * MAXN];
int head[MAXN], edgeNumber;

void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v, int w)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].w = w;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

int tset[MAXN];
int tmapNum;

int dist[MAXN];
int queue[MAXN];
bool visit[MAXN];

void spfa()
{
    memset(dist, -1, sizeof(dist));
    memset(visit, false, sizeof(visit));
    dist[0] = 0;
    visit[0] = true;
    queue[0] = 0;
    int front = 0, rear = 1;
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
}

int getIndex(int x)
{
    for (int i = 0; i < tmapNum; ++i)
    {
        if (tset[i] == x)
        {
            return i;
        }
    }
    tset[tmapNum] = x;
    return tmapNum++;
}

int main()
{
    int u, v;
    while (~scanf("%d%d%d", &T, &s, &p))
    {
        clearEdge();
        tmapNum = 0;
        getIndex(0);
        getIndex(T);
        for (int i = 0; i < p; ++i)
        {
            scanf("%d%d", &u, &v);
            u = getIndex(u);
            v = getIndex(v);
            addEdge(u, v, 0);
        }
        for (int i = 0; i < tmapNum; ++i)
        {
            for (int j = i + 1; j < tmapNum; ++j)
            {
                int u = tset[i];
                int v = tset[j];
                int w = ((int)fabs(u - v) - 1) / s + 1;
                addEdge(i, j, w);
                addEdge(j, i, w);
            }
        }
        spfa();
        printf("%d\n", dist[getIndex(T)]);
    }
    return 0;
}
