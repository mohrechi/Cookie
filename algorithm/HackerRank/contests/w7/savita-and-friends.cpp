#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXM = MAXN * 2;
const long long INF = 100000000000000000LL;

int N, M, K;
int A, B, C;
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

void addEdgeSub(int u, int v, int w)
{
    edge[edgeNum].v = v;
    edge[edgeNum].w = w;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

void addEdge(int u, int v, int w)
{
    addEdgeSub(u, v, w);
    addEdgeSub(v, u, w);
}

long long distA[MAXN];
long long distB[MAXN];
int queue[MAXN];
bool visit[MAXN];

void spfa(int start, long long dist[MAXN])
{
    for (int i = 1; i <= N; ++i)
    {
        dist[i] = INF;
        visit[i] = false;
    }
    dist[start] = 0;
    visit[start] = true;
    int front = 0, rear = 1;
    queue[front] = start;
    while (front != rear)
    {
        int u = queue[front];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            int w = edge[i].w;
            if (dist[v] > dist[u] + w)
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

struct Node
{
    long long u, v;
    bool operator <(const Node &node) const
    {
        if (u == node.u)
        {
            return v < node.v;
        }
        return u < node.u;
    }
} node[MAXN];

int main()
{
    int T, a, b, c;
    scanf("%d", &T);
    while (T--)
    {
        clearEdge();
        scanf("%d%d%d", &N, &M, &K);
        for (int i = 1; i <= M; ++i)
        {
            scanf("%d%d%d", &a, &b, &c);
            if (i == K)
            {
                A = a;
                B = b;
                C = c;
            }
            addEdge(a, b, c);
        }
        spfa(A, distA);
        spfa(B, distB);
        for (int i = 1; i <= N; ++i)
        {
            node[i].u = distA[i];
            node[i].v = distB[i];
        }
        sort(node + 1, node + N + 1);
        double x, ans = 1e100;
        double maxV = 0.0;
        int m = 0;
        node[0].u = -1;
        node[0].v = INF;
        for (int i = 1; i <= N; ++i)
        {
            if (node[i].v > maxV)
            {
                maxV = node[i].v;
            }
            while (node[i].u >= node[m].u && node[i].v >= node[m].v)
            {
                --m;
            }
            node[++m] = node[i];
        }
        if (maxV < ans)
        {
            x = C;
            ans = maxV;
        }
        if (node[m].u < ans)
        {
            x = 0;
            ans = node[m].u;
        }
        for (int i = 1; i < m; ++i)
        {
            double tx = (C + node[i + 1].v - node[i].u) * 0.5;
            double tAns = node[i].u + tx;
            if (tAns < ans)
            {
                ans = tAns;
                x = tx;
            }
        }
        printf("%.5f %.5f\n", x, ans);
    }
    return 0;
}
