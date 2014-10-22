#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int MAXN = 60010;

struct Edge
{
    int v, next;
}edge[MAXN];
int edgeNumber, head[MAXN];

inline void initEdge()
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

struct TreeNode
{
    int l, r, high;
}tree[MAXN * 3];

int n, m;
int low[MAXN], pos[MAXN];
struct Node
{
    int loyalty, ability, index;
    bool operator < (const Node &node) const
    {
        return ability > node.ability;
    }
}node[MAXN];
int ans[MAXN];
int timeStamp;

void dfs(int u)
{
    low[u] = MAXN;
    for(int i=head[u];i!=-1;i=edge[i].next)
    {
        int v = edge[i].v;
        dfs(v);
        low[u] = min(low[u], low[v]);
    }
    pos[u] = ++ timeStamp;
    low[u] = min(low[u], pos[u]);
}

void buildTree(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].high = -1;
    if(l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    buildTree(x << 1, l, mid);
    buildTree((x << 1) + 1, mid + 1, r);
}

void updateTree(int x, int pos, int value)
{
    if(tree[x].l == tree[x].r)
    {
        tree[x].high = value;
        return;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    tree[x].high = max(tree[x].high, value);
    if(pos <= mid)
    {
        updateTree(x << 1, pos, value);
    }
    else
    {
        updateTree((x << 1) + 1, pos, value);
    }
}

int queryTree(int x, int l, int r)
{
    if(l > r)
    {
        return -1;
    }
    if(tree[x].l == l && tree[x].r == r)
    {
        return tree[x].high;
    }
    int mid = (tree[x].l + tree[x].r) >> 1;
    if(r <= mid)
    {
        return queryTree(x << 1, l, r);
    }
    else if(l > mid)
    {
        return queryTree((x << 1) + 1, l, r);
    }
    else
    {
        return max(queryTree(x << 1, l, mid), queryTree((x << 1) + 1, mid + 1, r));
    }
}

int main()
{
    int caseNumber, u;
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        scanf("%d%d", &n, &m);
        initEdge();
        map<int, int> lmap;
        for(int i=1;i<n;++i)
        {
            scanf("%d%d%d", &u, &node[i].loyalty, &node[i].ability);
            node[i].index = i;
            addEdge(u, i);
            lmap[node[i].loyalty] = i;
        }
        timeStamp = 0;
        dfs(0);
        buildTree(1, 1, n);
        sort(node + 1, node + n);
        for(int i=1;i<n;++i)
        {
            ans[i] = 1000000;
        }
        for(int i=1;i<n;)
        {
            int cur = i;
            while(cur < n && node[cur].ability == node[i].ability)
            {
                int treePos = node[cur].index;
                int linePos = pos[treePos];
                ans[treePos] = queryTree(1, low[treePos], linePos - 1);
                if(ans[treePos] != -1)
                {
                    ans[treePos] = lmap[ans[treePos]];
                }
                ++ cur;
            }
            for(;i<cur;++i)
            {
                int treePos = node[i].index;
                int linePos = pos[treePos];
                updateTree(1, linePos, node[i].loyalty);
            }
        }
        while(m--)
        {
            scanf("%d", &u);
            printf("%d\n", ans[u]);
        }
    }
    return 0;
}
