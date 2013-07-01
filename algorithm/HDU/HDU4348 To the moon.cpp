#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 100010;

int n, m;
__int64 a[MAXN], sum[MAXN];

struct NumberNode
{
    __int64 d, nd;
}node[MAXN * 20];
int nodeNumber;

struct TimeNode
{
    int timeStamp, index;
};
vector<TimeNode> root[MAXN];

inline int lowbit(const int &x)
{
    return x & (-x);
}

void init()
{
    nodeNumber = 1;
    node[0].d = 0;
    node[0].nd = 0;
    TimeNode timeNode;
    for(int i=1;i<=n;++i)
    {
        root[i].clear();
        timeNode.timeStamp = 0;
        timeNode.index = 0;
        root[i].push_back(timeNode);
    }
}

inline int addNode(__int64 d, __int64 nd)
{
    node[nodeNumber].d = d;
    node[nodeNumber].nd = nd;
    return nodeNumber ++;
}

void update(int x, __int64 d, int timeStamp)
{
    __int64 nd = d * x;
    while(x <= n)
    {
        int u = root[x][root[x].size() - 1].index;
        TimeNode timeNode;
        timeNode.timeStamp = timeStamp;
        timeNode.index = addNode(node[u].d + d, node[u].nd + nd);
        root[x].push_back(timeNode);
        x += lowbit(x);
    }
}

__int64 query(int x)
{
    __int64 tx = x;
    __int64 sumd = 0;
    __int64 sumnd = 0;
    while(x > 0)
    {
        int u = root[x][root[x].size() - 1].index;
        sumd += node[u].d;
        sumnd += node[u].nd;
        x -= lowbit(x);
    }
    return sum[tx] + (tx + 1) * sumd - sumnd;
}

int find(int x, int timeStamp)
{
    for(int i=root[x].size()-1;i>=0;--i)
    {
        if(root[x][i].timeStamp <= timeStamp)
        {
            return root[x][i].index;
        }
    }
}

__int64 historyQuery(int x, int timeStamp)
{
    __int64 tx = x;
    __int64 sumd = 0;
    __int64 sumnd = 0;
    while(x > 0)
    {
        int u = find(x, timeStamp);
        sumd += node[u].d;
        sumnd += node[u].nd;
        x -= lowbit(x);
    }
    return sum[tx] + (tx + 1) * sumd - sumnd;
}

int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        init();
        for(int i=1;i<=n;++i)
        {
            scanf("%I64d", &a[i]);
            sum[i] = sum[i-1] + a[i];
        }
        int timeStamp = 0;
        char op[10];
        int l, r, d, t;
        while(m--)
        {
            scanf("%s", op);
            switch(*op)
            {
                case 'C':
                    scanf("%d%d%d", &l, &r, &d);
                    ++ timeStamp;
                    update(l, d, timeStamp);
                    update(r+1, -d, timeStamp);
                    break;
                case 'Q':
                    scanf("%d%d", &l, &r);
                    printf("%I64d\n", query(r) - query(l - 1));
                    break;
                case 'H':
                    scanf("%d%d%d", &l, &r, &t);
                    printf("%I64d\n", historyQuery(r, t) - historyQuery(l - 1, t));
                    break;
                case 'B':
                    scanf("%d", &t);
                    for(int i=1;i<=n;++i)
                    {
                        while(root[i][root[i].size()-1].timeStamp > t)
                        {
                            root[i].pop_back();
                        }
                    }
                    timeStamp = t;
                    break;
            }
        }
    }
    return 0;
}
