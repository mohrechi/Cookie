#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 300010;

int n;
__int64 nodeValue[MAXN], value[MAXN], number[MAXN];
__int64 ans;
struct Edge
{
    int u, v, c;
}edge[MAXN * 2];
int edgeNumber, head[MAXN];

inline void addEdge(int u, int v, int c)
{
    edge[edgeNumber].u = u;
    edge[edgeNumber].v = v;
    edge[edgeNumber].c = c;
    ++ edgeNumber;
}

bool compare1(const Edge &a, const Edge &b)
{
    return a.u < b.u;
}

bool compare2(const Edge &a, const Edge &b)
{
    return a.c < b.c;
}

void dfs(int x, int father, int fatherColor)
{
    __int64 lastValue = 0, lastNumber = 0;
    __int64 currentValue = 0, currentNumber = 0;
    int lastColor = -1;
    value[x] = nodeValue[x];
    number[x] = 1;
    for(int i=head[x];i!=-1 && edge[i].u==x;++i)
    {
        if(edge[i].v == father)
        {
            continue;
        }
        dfs(edge[i].v, x, edge[i].c);
        if(edge[i].c != lastColor)
        {
            lastValue = currentValue;
            lastNumber = currentNumber;
            lastColor = edge[i].c;
        }
        ans += lastValue * number[edge[i].v];
        ans += lastNumber * value[edge[i].v];
        ans += lastNumber * number[edge[i].v] * nodeValue[x];
        currentValue += value[edge[i].v];
        currentNumber += number[edge[i].v];
        if(fatherColor != edge[i].c)
        {
            number[x] += number[edge[i].v];
            value[x] += value[edge[i].v];
            value[x] += number[edge[i].v] * nodeValue[x];
        }
    }
    if(x != 1)
    {
        ans += number[x] * nodeValue[father];
        ans += value[x];
    }
}

int main()
{
    int u, v, c;
    while(~scanf("%d", &n))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%I64d", &nodeValue[i]);
        }
        edgeNumber = 0;
        for(int i=1;i<n;++i)
        {
            scanf("%d%d%d", &u, &v, &c);
            addEdge(u, v, c);
            addEdge(v, u, c);
        }
        sort(edge, edge + edgeNumber, compare1);
        memset(head, -1, sizeof(head));
        int start = 0;
        head[edge[0].u] = 0;
        for(int i=1;i<edgeNumber;++i)
        {
            if(edge[i].u != edge[i-1].u)
            {
                sort(edge + start, edge + i, compare2);
                start = i;
                head[edge[i].u] = i;
            }
        }
        sort(edge + start, edge + edgeNumber, compare2);
        ans = 0;
        dfs(1, 0, -1);
        printf("%I64d\n", ans);
    }
    return 0;
}
