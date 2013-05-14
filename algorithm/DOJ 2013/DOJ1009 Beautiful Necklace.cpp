#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 11;
const int MAXM = 5;
const int MAXL = 1005;

//#define DEBUG

const int mod[] = {0, 1, 10, 100, 1000, 10000};

int n, m;
struct Edge
{
    int v, next;
} edge[MAXL * MAXN];
int head[MAXL], edgeNumber;

void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

bool isValid(int x)
{
    if (x == 0)
    {
        return true;
    }
    int count = 0;
    while (x)
    {
        if (x % 10 >= n)
        {
            return false;
        }
        x /= 10;
        ++count;
    }
    return count < m;
}

#ifdef DEBUG
void printNode(int x)
{
    if (x == 0)
    {
        for (int i = 1; i < m; ++i)
        {
            printf("0");
        }
    }
    else
    {
        int count = 0;
        int temp = x;
        while (temp)
        {
            ++count;
            temp /= 10;
        }
        count = m - count;
        for (int i = 1; i < count; ++i)
        {
            printf("0");
        }
        printf("%d", x);
    }
}

void printGraph()
{
    for (int i = 0; i < MAXL; ++i)
    {
        if (head[i] != -1)
        {
            printNode(i);
            printf(": ");
            for (int j = head[i]; j != -1; j = edge[j].next)
            {
                printNode(edge[j].v);
                printf(" ");
            }
            printf("\n");
        }
    }
}
#endif

bool nVisit[MAXL];
int ans[MAXL * MAXN];
bool visit[MAXL * MAXN];

bool dfs1(int u, int depth)
{
    if (depth == edgeNumber)
    {
        return true;
    }
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        if (!visit[i])
        {
            visit[i] = true;
            ans[depth] = edge[i].v;
            if (dfs1(edge[i].v, depth + 1))
            {
                return true;
            }
            visit[i] = false;
        }
    }
    return false;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        if (m == 1)
        {
            for (int i = 0; i < n; ++i)
            {
                printf("%d", i);
            }
            printf("\n");
        }
        else
        {
            clearEdge();
            for (int i = 0; i < MAXL; ++i)
            {
                if (isValid(i))
                {
                    for (int j = n - 1; j >= 0; --j)
                    {
                        addEdge(i, (i * 10 + j) % mod[m]);
                    }
                }
            }
            #ifdef DEBUG
            //printGraph();
            #endif
            memset(visit, false, sizeof(visit));
            dfs1(0, 0);
            for (int i = 0; i < m - 1; ++i)
            {
                printf("0");
            }
            for (int i = 0; i < edgeNumber - m + 1; ++i)
            {
                printf("%d", ans[i] % 10);
            }
            printf("\n");
        }
    }
    return 0;
}
