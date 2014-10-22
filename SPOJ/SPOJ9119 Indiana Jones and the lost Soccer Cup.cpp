#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXM = 1e5 + 5;

int n, m;
struct Edge
{
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNum;
int in[MAXN];

void clearEdge()
{
    edgeNum = 0;
    memset(in, 0, sizeof(in));
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v)
{
    edge[edgeNum].v = v;
    edge[edgeNum].next = head[u];
    head[u] = edgeNum++;
}

bool visit[MAXN];
int stack[MAXN], top;
int dfn[MAXN], low[MAXN], timeStamp;

bool dfs(int u)
{
    dfn[u] = low[u] = ++timeStamp;
    stack[top++] = u;
    visit[u] = true;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (dfn[v] == -1)
        {
            if (dfs(v))
            {
                return true;
            }
            low[u] = min(low[u], low[v]);
        }
        else if (visit[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        int temp, num = 0;
        do
        {
            temp = stack[--top];
            visit[temp] = false;
            ++num;
        }
        while (temp != u);
        if (num >= 2)
        {
            return true;
        }
    }
    return false;
}

bool containCircle()
{
    timeStamp = top = 0;
    memset(visit, false, sizeof(visit));
    memset(dfn, -1, sizeof(dfn));
    for (int i = 1; i <= n; ++i)
    {
        if (dfn[i] == -1)
        {
            if (dfs(i))
            {
                return true;
            }
        }
    }
    return false;
}

int ans[MAXN];

int main()
{
    int T;
    int u, v;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        clearEdge();
        for (int i = 0; i < m; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            ++in[v];
        }
        bool missing = false;
        bool recheck = false;
        if (containCircle())
        {
            recheck = true;
        }
        int inIndex = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (in[i] == 0)
            {
                if (inIndex == -1)
                {
                    inIndex = i;
                }
                else
                {
                    missing = true;
                }
            }
        }
        if (inIndex == -1)
        {
            recheck = true;
        }
        ans[0] = inIndex;
        for (int i = 1; i < n && !missing && !recheck; ++i)
        {
            int next = -1;
            for (int j = head[inIndex]; j != -1; j = edge[j].next)
            {
                int v = edge[j].v;
                if (--in[v] == 0)
                {
                    if (next == -1)
                    {
                        next = v;
                    }
                    else
                    {
                        missing = true;
                        break;
                    }
                }
            }
            if (next == -1)
            {
                recheck = true;
            }
            ans[i] = inIndex = next;
        }
        if (recheck)
        {
            printf("recheck hints\n");
        }
        else if (missing)
        {
            printf("missing hints\n");
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (i)
                {
                    printf(" ");
                }
                printf("%d", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
