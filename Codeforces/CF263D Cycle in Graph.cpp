#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MAXM = 100005 * 2;

struct Edge
{
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNumber;
int n, m, k;

void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

int ans[MAXN];
bool visit[MAXN];

void find(int u, int d)
{
    if(!visit[u])
    {
        visit[u] = true;
        ans[d ++] = u;
        if(d > k)
        {
            for(int i=head[u];i;i=edge[i].next)
            {
                int v = edge[i].v;
                if(v == ans[0])
                {
                    printf("%d\n", d);
                    for(int i=0;i<d;++i)
                    {
                        printf("%d ", ans[i]);
                    }
                    printf("\n");
                    exit(0);
                }
            }
        }
        for(int i=head[u];i;i=edge[i].next)
        {
            find(edge[i].v, d);
        }
        visit[u] = false;
    }
}

int main()
{
    int u, v;
    scanf("%d%d%d", &n, &m, &k);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    for(int i=1;i<=n;++i)
    {
        find(i, 0);
    }
    return 0;
}
