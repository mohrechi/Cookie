#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 305;
const int MAXM = 2 * MAXN * MAXN;
const int MAXE = 50005 * 2;

int n, v, e;
int a[MAXN], b[MAXN];
int color[MAXN], colorNum;
long long sa[MAXN], sb[MAXN];

struct Edge
{
    int v, next;
} edge[MAXE];
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

void dfs(int u, int colorIndex)
{
    color[u] = colorIndex;
    sa[colorIndex] += a[u];
    sb[colorIndex] += b[u];
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (color[v] == -1)
        {
            dfs(v, colorIndex);
        }
    }
}

bool possible()
{
    colorNum = 0;
    memset(color, -1, sizeof(color));
    memset(sa, 0, sizeof(sa));
    memset(sb, 0, sizeof(sb));
    for (int i = 1; i <= n; ++i)
    {
        if (color[i] == -1)
        {
            dfs(i, colorNum++);
        }
    }
    for (int i = 0; i < colorNum; ++i)
    {
        if (sa[i] != sb[i])
        {
            return false;
        }
    }
    return true;
}

struct Move
{
    int u, v, d;
    inline void output() const
    {
        printf("%d %d %d\n", u, v, d);
    }
} move[MAXM];
int moveNum;

bool visit[MAXN];
int queue[MAXN];
int back[MAXN];

void findPath(int src, int dst)
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    visit[src] = true;
    queue[0] = src;
    back[src] = -1;
    while (front < rear)
    {
        int u = queue[front++];
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if (!visit[v])
            {
                visit[v] = true;
                back[v] = u;
                queue[rear++] = v;
                if (v == dst)
                {
                    return;
                }
            }
        }
    }
}

void transfer(int src, int dst, int amount)
{
    if (src == dst)
    {
        return;
    }
    int real = min(a[back[dst]], amount);
    move[moveNum].u = back[dst];
    move[moveNum].v = dst;
    move[moveNum].d = real;
    if (real)
    {
        ++moveNum;
        a[back[dst]] -= real;
        a[dst] += real;
    }
    transfer(src, back[dst], amount);
    if (real < amount)
    {
        real = amount - real;
        move[moveNum].u = back[dst];
        move[moveNum].v = dst;
        move[moveNum].d = real;
        ++moveNum;
        a[back[dst]] -= real;
        a[dst] += real;
    }
}

int main()
{
    int u, v;
    while (~scanf("%d%d%d", &n, &v, &e))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &b[i]);
        }
        clearEdge();
        for (int i = 0; i < e; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
        }
        if (possible())
        {
            moveNum = 0;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = i + 1; j <= n && a[i] != b[i]; ++j)
                {
                    if (color[i] != color[j])
                    {
                        continue;
                    }
                    if (a[i] < b[i] && a[j] > b[j])
                    {
                        findPath(j, i);
                        transfer(j, i, min(b[i] - a[i], a[j] - b[j]));
                    }
                    else if (a[i] > b[i] && a[j] < b[j])
                    {
                        findPath(i, j);
                        transfer(i, j, min(a[i] - b[i], b[j] - a[j]));
                    }
                }
            }
            printf("%d\n", moveNum);
            for (int i = 0; i < moveNum; ++i)
            {
                move[i].output();
            }
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
