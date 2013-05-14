#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;

int n, m;
struct Edge
{
    int v, next;
} edge[MAXN * MAXN];
int head[MAXN], edgeNumber;

inline void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

bool visit[MAXN];

void dfs(int u)
{
    visit[u] = true;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(!visit[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    int k, a;
    while(~scanf("%d%d", &n, &m))
    {
        int ans = 0;
        clearEdge();
        for(int i = 0; i < n; ++ i)
        {
            scanf("%d", &k);
            if(k)
            {
                ans = -1;
            }
            for(int j = 0; j < k; ++ j)
            {
                scanf("%d", &a);
                addEdge(i, n + a - 1);
                addEdge(n + a - 1, i);
            }
        }
        memset(visit, false, sizeof(visit));
        for(int i = 0; i < n; ++ i)
        {
            if(!visit[i])
            {
                dfs(i);
                ++ ans;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
