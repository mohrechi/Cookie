#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 505;
const int MAXM = MAXN * MAXN;

int n, m;
int oldRank[MAXN];
bool rank[MAXN][MAXN];
bool possible;
int ans[MAXN];

struct Edge
{
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNum;
int in[MAXN];

void clearEdge()
{
    edgeNum = 0;
    memset(head, -1, sizeof(head));
    memset(in, 0, sizeof(in));
}

void addEdge(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
    ++in[v];
}

bool out[MAXN];

void topology()
{
    possible = true;
    memset(out, false, sizeof(out));
    int outNum = 0;
    int index = 0;
    while (outNum < n)
    {
        int num = 0;
        int pos;
        for (int i = 1; i <= n; ++i)
        {
            if (!out[i] && in[i] == 0)
            {
                ++num;
                pos = i;
            }
        }
        if (num == 0)
        {
            possible = false;
            break;
        }
        if (num == 1)
        {
            ans[index++] = pos;
            for (int i = head[pos]; i != -1; i = edge[i].next)
            {
                int v = edge[i].v;
                --in[v];
            }
            out[pos] = true;
            ++outNum;
        }
    }
}

int main()
{
    int T, u, v;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &oldRank[i]);
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                rank[oldRank[i]][oldRank[j]] = true;
                rank[oldRank[j]][oldRank[i]] = false;
            }
        }
        scanf("%d", &m);
        while (m--)
        {
            scanf("%d%d", &u, &v);
            rank[u][v] = !rank[u][v];
            rank[v][u] = !rank[v][u];
        }
        clearEdge();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (rank[i][j])
                {
                    addEdge(i, j);
                }
                else
                {
                    addEdge(j, i);
                }
            }
        }
        topology();
        if (possible)
        {
            for (int i = 0; i < n; ++i)
            {
                if (i)
                {
                    printf(" ");
                }
                if (ans[i] == -1)
                {
                    printf("?");
                }
                else
                {
                    printf("%d", ans[i]);
                }
            }
            printf("\n");
        }
        else
        {
            printf("IMPOSSIBLE\n");
        }
    }
    return 0;
}
