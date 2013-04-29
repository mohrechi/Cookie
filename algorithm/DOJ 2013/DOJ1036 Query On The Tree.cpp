#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int N, Q;
int w[MAXN];
int maxValue[MAXN], minValue[MAXN];
int countValue[MAXN];
long long sumValue[MAXN];

struct Edge
{
    int v, next;
} edge[MAXN * 2];
int head[MAXN], edgeNumber;

void clearEdge()
{
    edgeNumber = 0;
    memset(head, -1, sizeof(head));
}

inline void addEdgeSub(int u, int v)
{
    edge[edgeNumber].v = v;
    edge[edgeNumber].next = head[u];
    head[u] = edgeNumber++;
}

inline void addEdge(int u, int v)
{
    addEdgeSub(u, v);
    addEdgeSub(v, u);
}

int timeStamp;
int pos[MAXN];
int left[MAXN];

void treeDp(int u, int f)
{
    maxValue[u] = w[u];
    minValue[u] = w[u];
    sumValue[u] = w[u];
    countValue[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f)
        {
            treeDp(v, u);
            maxValue[u] = max(maxValue[u], maxValue[v]);
            minValue[u] = min(minValue[u], minValue[v]);
            sumValue[u] += sumValue[v];
            countValue[u] += countValue[v];
        }
    }
    pos[u] = ++timeStamp;
    left[u] = pos[u];
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if (v != f)
        {
            left[u] = min(left[u], left[v]);
        }
    }
}

struct TreeNode
{
    int l, r;
}node[MAXN<<2];

int leftNumber[20][MAXN];
int treeValue[20][MAXN];
int sortedArray[MAXN];

void buildTree(int l, int r, int c, int d)
{
    node[c].l = l;
    node[c].r = r;
    if(l == r) return;
    int mid = (l + r) >> 1;
    int sameNumber = mid - l + 1;
    for(int i=l;i<=r;++i)
    if(treeValue[d][i] < sortedArray[mid])
        --sameNumber;
    int pLeft = l, pRight = mid + 1;
    for(int i=l;i<=r;++i)
    {
        leftNumber[d][i] = (i==l?0:leftNumber[d][i-1]);
        if(treeValue[d][i] < sortedArray[mid])
        {
            treeValue[d+1][pLeft++] =
            treeValue[d][i];
            ++leftNumber[d][i];
        }
        else if(treeValue[d][i] >sortedArray[mid])
        {
            treeValue[d+1][pRight++] =
            treeValue[d][i];
        }
        else if(sameNumber)
        {
            treeValue[d+1][pLeft++] =
            treeValue[d][i];
            ++leftNumber[d][i];
            --sameNumber;
        }
        else
        {
            treeValue[d+1][pRight++] =
            treeValue[d][i];
        }
    }
    buildTree(l, mid, (c<<1)+1, d + 1);
    buildTree(mid+1, r, (c<<1)+2, d + 1);
}

int query(int l, int r, int c, int d, int k)
{
    if(l == r) return treeValue[d][l];
    int lLeft = (l==node[c].l?0:leftNumber[d][l-1]);
    int rLeft = leftNumber[d][r];
    int totalLeft = rLeft - lLeft;
    if(k <= totalLeft)
    {
        return query(node[c].l + lLeft, node[c].l + rLeft - 1, (c<<1)+1, d+1, k);
    }
    int mid = (node[c].l + node[c].r) >> 1;
    int lRight = l - node[c].l - lLeft;
    int totalRight = r - l + 1 - totalLeft;
    return query(mid + lRight + 1, mid + lRight + totalRight, (c<<1)+2, d + 1, k - totalLeft);
}

int main()
{
    int u, v;
    char op[10];
    while (~scanf("%d", &N))
    {
        for (int i = 1; i <= N; ++i)
        {
            scanf("%d", &w[i]);
        }
        clearEdge();
        for (int i = 1; i < N; ++i)
        {
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        timeStamp = 0;
        treeDp(1, -1);
        for (int i = 1; i <= N; ++i)
        {
            sortedArray[pos[i] - 1] = w[i];
            treeValue[0][pos[i] - 1] = w[i];
        }
        sort(sortedArray, sortedArray + N);
        buildTree(0, N - 1, 0, 0);
        scanf("%d", &Q);
        for (int i = 0; i < Q; ++i)
        {
            scanf("%s", op);
            switch (op[1])
            {
            case 'A':
                scanf("%d", &u);
                printf("%d\n", maxValue[u]);
                break;
            case 'I':
                scanf("%d", &u);
                printf("%d\n", minValue[u]);
                break;
            case 'U':
                scanf("%d", &u);
                printf("%lld\n", sumValue[u]);
                break;
            case 'T':
                scanf("%d%d", &u, &v);
                if (v > countValue[u])
                {
                    printf("-1\n");
                }
                else
                {
                    printf("%d\n", query(left[u] - 1, pos[u] - 1, 0, 0, v));
                }
                break;
            }
        }
    }
    return 0;
}
