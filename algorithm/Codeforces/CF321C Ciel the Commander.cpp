#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n;
struct Edge
{
    int v, next;
} edge[MAXN * 2];
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

int rank[MAXN];
int appear[MAXN];
int block[MAXN];

void dfs(int u, int f)
{
    int childNum = 0;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f)
        {
            dfs(v, u);
            ++childNum;
        }
    }
    if (childNum == 0)
    {
        rank[u] = 26;
        appear[u] = 1 << 26;
        block[u] = 1 << 26;
    }
    else
    {
        int near = 0;
        appear[u] = 0;
        block[u] = 0;
        for (int i = head[u]; i != -1; i = edge[i].next)
        {
            int v = edge[i].v;
            if (v != f)
            {
                near |= 1 << rank[v];
                appear[u] |= appear[v];
                block[u] |= block[v];
            }
        }
        if (childNum == 1)
        {
            for (int i = 26; i >= 1; --i)
            {
                if ((near & (1 << i)) == 0 && (block[u] & (1 << i)) == 0)
                {
                    rank[u] = i;
                    appear[u] |= 1 << i;
                    block[u] &= (1 << i) - 1;
                    block[u] |= 1 << i;
                    break;
                }
            }
        }
        else
        {
            for (int i = 1; i <= 26; ++i)
            {
                if (appear[u] & (1 << i))
                {
                    rank[u] = --i;
                    appear[u] |= 1 << i;
                    block[u] = 1 << i;
                    break;
                }
            }
        }
    }
}

int main()
{
    int a, b;
    while (~scanf("%d", &n))
    {
        clearEdge();
        for (int i = 1; i < n; ++i)
        {
            scanf("%d%d", &a, &b);
            addEdge(a, b);
            addEdge(b, a);
        }
        dfs(1, 0);
        for (int i = 1; i <= n; ++i)
        {
            if (i > 1)
            {
                printf(" ");
            }
            printf("%c", rank[i] - 1 + 'A');
        }
        printf("\n");
    }
    return 0;
}
