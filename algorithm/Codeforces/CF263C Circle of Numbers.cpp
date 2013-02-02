#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MAXM = MAXN * 4;

struct Edge
{
    int v, next;
} edge[MAXM];
int head[MAXN], edgeNumber;

void initEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

int n, ans[MAXN];
bool exist, visit[MAXN];

void getConnect(int a[], int u)
{
    int m = 0;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        a[m++] = edge[i].v;
    }
}

bool solve(int u, int f, int d)
{
    if(d == n)
    {
        return true;
    }
    if(!visit[u])
    {
        visit[u] = true;
        ans[d] = u;
        if(f == -1)
        {
            for(int i=head[u];i!=-1;i=edge[i].next)
            {
                int v = edge[i].v;
                if(solve(v, u, d + 1))
                {
                    return true;
                }
            }
        }
        else
        {
            for(int i=head[u];i!=-1;i=edge[i].next)
            {
                int v = edge[i].v;
                if(v == f)
                {
                    continue;
                }
                bool flag1 = false;
                bool flag2 = false;
                for(int j=head[v];j!=-1;j=edge[j].next)
                {
                    if(edge[j].v == u)
                    {
                        flag1 = true;
                    }
                    if(edge[j].v == f)
                    {
                        flag2 = true;
                    }
                }
                if(flag1 && flag2)
                {
                    if(solve(v, u, d + 1))
                    {
                        return true;
                    }
                }
            }
        }
        visit[u] = false;
    }
    return false;
}

int num[MAXN];

int main()
{
    int m, u, v;
    while(~scanf("%d", &n))
    {
        m = n << 1;
        initEdge();
        memset(num, 0, sizeof(num));
        for(int i=0;i<m;++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
            addEdge(v, u);
            ++ num[u];
            ++ num[v];
        }
        bool flag = true;
        for(int i=1;i<=n;++i)
        {
            if(num[i] != 4)
            {
                flag = false;
                break;
            }
        }
        exist = false;
        if(flag)
        {
            memset(visit, false, sizeof(visit));
            exist = solve(1, -1, 0);
        }
        if(exist)
        {
            int node = 1;
            for(int i=0;i<n;++i)
            {
                if(i)
                {
                    printf(" ");
                }
                printf("%d", ans[i]);
            }
            printf("\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
