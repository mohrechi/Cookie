#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int MAXM = MAXN * MAXN;

struct Interval
{
    int a, b;
} interval[MAXN];
int intervalNum;

struct Edge
{
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNum;

void clearEdge()
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

bool judge(int a, int b, int c, int d)
{
    return (c < a && a < d) || (c < b && b < d);
}

bool visit[MAXN];
int queue[MAXN];

bool find(int src, int dst)
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    visit[src] = true;
    queue[0] = src;
    while (front < rear)
    {
        int u = queue[front++];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if (!visit[v])
            {
                visit[v] = true;
                queue[rear++] = v;
            }
        }
    }
    return visit[dst];
}

int main()
{
    int n, o, x, y;
    while (~scanf("%d", &n))
    {
        intervalNum = 1;
        clearEdge();
        while (n--)
        {
            scanf("%d%d%d", &o, &x, &y);
            if (o == 1)
            {
                interval[intervalNum].a = x;
                interval[intervalNum].b = y;
                for (int i = 1; i < intervalNum; ++i)
                {
                    if (judge(interval[i].a, interval[i].b, interval[intervalNum].a, interval[intervalNum].b))
                    {
                        addEdge(i, intervalNum);
                    }
                    if (judge(interval[intervalNum].a, interval[intervalNum].b, interval[i].a, interval[i].b))
                    {
                        addEdge(intervalNum, i);
                    }
                }
                ++intervalNum;
            }
            else
            {
                if (find(x, y))
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
        }
    }
    return 0;
}
