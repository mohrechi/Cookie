//#define METHOD_GREEDY
#define METHOD_BIPARTITE

#ifdef METHOD_GREEDY
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

struct Node
{
    int x, y;
    Node(){}
    Node (int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    inline void input()
    {
        scanf("%d%d", &x, &y);
    }
    Node horizon()
    {
        return Node(x + 1, y);
    }
    Node vertical()
    {
        return Node(x, y + 1);
    }
} h[MAXN], v[MAXN];

bool operator ==(const Node &a ,const Node &b)
{
    return a.x == b.x && a.y == b.y;
}

int n, m;
int father[MAXN * 2];
int num[MAXN * 2];

void init()
{
    for (int i = 0; i < (n + m); ++i)
    {
        father[i] = i;
        num[i] = 1;
    }
}

int find(int x)
{
    if (x == father[x])
    {
        return x;
    }
    return father[x] = find(father[x]);
}

void combine(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        num[x] += num[y];
        num[y] = 0;
        father[y] = x;
        father[y] = x;
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m), n || m)
    {
        for (int i = 0; i < n; ++i)
        {
            h[i].input();
        }
        for (int i = 0; i < m; ++i)
        {
            v[i].input();
        }
        init();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (v[i] == h[j] ||
                    v[i] == h[j].horizon() ||
                    v[i].vertical() == h[j] ||
                    v[i].vertical() == h[j].horizon())
                {
                    combine(i + n, j);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < (n + m); ++i)
        {
            sum += num[i] >> 1;
        }
        printf("%d\n", n + m - sum);
    }
    return 0;
}
#endif

#ifdef METHOD_BIPARTITE
#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 1005;
const int MAXM = 105;

int n, m;
struct Edge
{
    int v, next;
} edge[MAXN * 4];
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

struct Node
{
    int x, y;
    Node() {}
    Node(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    inline void input()
    {
        scanf("%d%d", &x, &y);
    }
    const Node horizon() const
    {
        return Node(x + 1, y);
    }
    const Node vertical() const
    {
        return Node(x, y + 1);
    }
};

int map[MAXM][MAXM];

int getMap(const Node &node)
{
    return map[node.x][node.y];
}

void setMap(const Node &node, int value)
{
    map[node.x][node.y] = value;
}

int link[MAXN];
bool visit[MAXN];

bool find(int u)
{
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (!visit[v])
        {
            visit[v] = true;
            if (link[v] == -1 || find(link[v]))
            {
                link[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungary()
{
    int res = 0;
    memset(link, -1, sizeof(link));
    for (int i = 0; i < m; ++i)
    {
        memset(visit, false, sizeof(visit));
        if (find(i))
        {
            ++res;
        }
    }
    return res;
}

int main()
{
    Node node;
    while (scanf("%d%d", &n, &m), n | m)
    {
        clearEdge();
        memset(map, -1, sizeof(map));
        for (int i = 0; i < n; ++i)
        {
            node.input();
            setMap(node, i);
            setMap(node.horizon(), i);
        }
        for (int i = 0; i < m; ++i)
        {
            node.input();
            if (getMap(node) != -1)
            {
                addEdge(i, getMap(node));
            }
            if (getMap(node.vertical()) != -1)
            {
                addEdge(i, getMap(node.vertical()));
            }
        }
        printf("%d\n", n + m - hungary());
    }
    return 0;
}
#endif
