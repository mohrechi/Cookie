#include <cstdio>
#include <cstring>
const int MAXN = 100005;
int n, m;
int c[MAXN], index[MAXN];
int low[MAXN];
bool apple[MAXN];

inline int lowbit(int x)
{
    return x & (-x);
}

void update(int x, int value)
{
    while(x <= n)
    {
        c[x] += value;
        x += lowbit(x);
    }
}

int query(int x)
{
    int sum = 0;
    while(x > 0)
    {
        sum += c[x];
        x -= lowbit(x);
    }
    return sum;
}

struct Edge
{
    int v, next;
}edge[MAXN];
int edgeNumber, head[MAXN];
int indexNumber;

void addEdge(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber ++;
}

void dfs(int x)
{
    low[x] = MAXN;
    for(int i=head[x];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        dfs(v);
        if(low[x] > low[v])
        {
            low[x] = low[v];
        }
    }
    index[x] = indexNumber ++;
    if(low[x] > index[x])
    {
        low[x] = index[x];
    }
}

int main()
{
    int u, v, x;
    char op[4];
    scanf("%d", &n);
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
    for(int i=1;i<n;++i)
    {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    indexNumber = 1;
    dfs(1);
    memset(apple, true, sizeof(apple));
    for(int i=1;i<=n;++i)
    {
        c[i] = lowbit(i);
    }
    scanf("%d", &m);
    while(m--)
    {
        scanf("%s%d", op, &x);
        if(*op == 'Q')
        {
            printf("%d\n", query(index[x]) - query(low[x] - 1));
        }
        else
        {
            if(apple[x])
            {
                apple[x] = false;
                update(index[x], -1);
            }
            else
            {
                apple[x] = true;
                update(index[x], 1);
            }
        }
    }
    return 0;
}
