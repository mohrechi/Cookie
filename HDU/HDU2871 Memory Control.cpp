#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50000 + 10;
const int MAXM = 50000 + 10;

//#define DEBUG

struct TreeNode
{
    int l, r;
    int id;
    int lazy;
    int freeL;
    int freeR;
    int freeC;
    int start;
    int leftId;
    int rightId;
    int size;
} tree[MAXN * 4];

void pushUp(int x)
{
    int l = x << 1;
    int r = l + 1;
    if (tree[l].freeL == tree[l].r - tree[l].l + 1)
    {
        tree[x].freeL = tree[l].freeL + tree[r].freeL;
    }
    else
    {
        tree[x].freeL = tree[l].freeL;
    }
    if (tree[r].freeR == tree[r].r - tree[r].l + 1)
    {
        tree[x].freeR = tree[r].freeR + tree[l].freeR;
    }
    else
    {
        tree[x].freeR = tree[r].freeR;
    }
    tree[x].freeC = 0;
    tree[x].start = tree[x].r + 1;
    if (tree[l].freeC > tree[x].freeC)
    {
        tree[x].freeC = tree[l].freeC;
        tree[x].start = tree[l].start;
    }
    if (tree[l].freeR + tree[r].freeL > tree[x].freeC)
    {
        tree[x].freeC = tree[l].freeR + tree[r].freeL;
        tree[x].start = tree[l].r - tree[l].freeR + 1;
    }
    if (tree[r].freeC > tree[x].freeC)
    {
        tree[x].freeC = tree[r].freeC;
        tree[x].start = tree[r].start;
    }
    tree[x].leftId = tree[l].leftId;
    tree[x].rightId = tree[r].rightId;
    tree[x].size = tree[l].size + tree[r].size;
    if (tree[l].rightId == tree[r].leftId && tree[l].rightId > 0)
    {
        --tree[x].size;
    }
}

void pushDown(int x)
{
    if (tree[x].lazy)
    {
        int l = x << 1;
        int r = l + 1;
        int lazy = tree[x].lazy;
        tree[l].id = lazy;
        tree[l].lazy = lazy;
        tree[r].id = lazy;
        tree[r].lazy = lazy;
        tree[l].freeL = tree[l].freeR = tree[l].freeC = -1 == lazy ? tree[l].r - tree[l].l + 1 : 0;
        tree[r].freeL = tree[r].freeR = tree[r].freeC = -1 == lazy ? tree[r].r - tree[r].l + 1 : 0;
        tree[l].start = tree[l].l;
        tree[r].start = tree[r].l;
        tree[l].leftId = lazy;
        tree[l].rightId = lazy;
        tree[l].size = -1 != lazy;
        tree[r].leftId = lazy;
        tree[r].rightId = lazy;
        tree[r].size = -1 != lazy;
        tree[x].lazy = 0;
    }
}

void build(int x, int l, int r)
{
    tree[x].l = l;
    tree[x].r = r;
    tree[x].id = -1;
    tree[x].lazy = 0;
    if (l == r)
    {
        tree[x].freeL = 1;
        tree[x].freeR = 1;
        tree[x].freeC = 1;
        tree[x].start = l;
        tree[x].leftId = -1;
        tree[x].rightId = -1;
        tree[x].size = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(x << 1, l, mid);
    build((x << 1) + 1, mid + 1, r);
    pushUp(x);
}

void update(int x, int l, int r, int id)
{
    if (tree[x].l == l && tree[x].r == r)
    {
        tree[x].id = id;
        tree[x].lazy = id;
        tree[x].freeL = tree[x].freeR = tree[x].freeC = -1 == id ? tree[x].r - tree[x].l + 1 : 0;
        tree[x].start = tree[x].l;
        tree[x].leftId = id;
        tree[x].rightId = id;
        tree[x].size = id != -1;
        return;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (r <= mid)
    {
        update(x << 1, l, r, id);
    }
    else if (l > mid)
    {
        update((x << 1) + 1, l, r, id);
    }
    else
    {
        update(x << 1, l, mid, id);
        update((x << 1) + 1, mid + 1, r, id);
    }
    pushUp(x);
}

int queryFree(int x, int len)
{
    if (len > tree[x].freeC)
    {
        return -1;
    }
    if (tree[x].l == tree[x].r)
    {
        return tree[x].l;
    }
    pushDown(x);
    int l = x << 1;
    int r = l + 1;
    if (tree[l].freeL >= len)
    {
        return tree[l].l;
    }
    if (tree[l].freeC >= len)
    {
        return queryFree(l, len);
    }
    if (tree[l].freeR + tree[r].freeL >= len)
    {
        return tree[l].r - tree[l].freeR + 1;
    }
    return queryFree(r, len);
}

int queryPos(int x, int pos)
{
    if (tree[x].l == tree[x].r)
    {
        return tree[x].id;
    }
    pushDown(x);
    int mid = (tree[x].l + tree[x].r) >> 1;
    if (pos <= mid)
    {
        return queryPos(x << 1, pos);
    }
    return queryPos((x << 1) + 1, pos);
}

int queryKth(int x, int k)
{
    if (k > tree[x].size || 0 == k)
    {
        return -1;
    }
    if (tree[x].l == tree[x].r)
    {
        return tree[x].id;
    }
    pushDown(x);
    if (k <= tree[x << 1].size)
    {
        return queryKth(x << 1, k);
    }
    if (tree[x << 1].rightId == tree[(x << 1) + 1].leftId && tree[x << 1].rightId != -1)
    {
        return queryKth((x << 1) + 1, k - tree[x << 1].size + 1);
    }
    return queryKth((x << 1) + 1, k - tree[x << 1].size);
}

#ifdef DEBUG
void printTree(int x = 1, int space = 0)
{
    for (int i = 0; i < space; ++i)
    {
        putchar(' ');
    }
    printf("%d %d %d: %d %d  %d %d %d  %d    %d %d %d\n", x, tree[x].l, tree[x].r,
           tree[x].id, tree[x].lazy,
           tree[x].freeL, tree[x].freeR, tree[x].freeC,
           tree[x].start,
           tree[x].leftId, tree[x].rightId, tree[x].size);
    if (tree[x].l == tree[x].r)
    {
        return;
    }
    printTree(x << 1, space + 4);
    printTree((x << 1) + 1, space + 4);
}

void printMemory(int x, int lazy)
{
    if (tree[x].l == tree[x].r)
    {
        if (-1 == lazy)
        {
            printf("_ ");
        }
        else if (lazy > 0)
        {
            printf("%d ", lazy);
        }
        else
        {
            printf("%d ", tree[x].id);
        }
        return;
    }
    if (lazy)
    {
        printMemory(x << 1, lazy);
        printMemory((x << 1) + 1, lazy);
    }
    else
    {
        printMemory(x << 1, tree[x].lazy);
        printMemory((x << 1) + 1, tree[x].lazy);
    }
}

void printMemory()
{
    printf("Memory: \n");
    printMemory(1, 0);
    putchar('\n');
}
#endif // DEBUG

int n, m;
int start[MAXM];
int end[MAXN];

int main()
{
    int x, len;
    char op[10];
    while (~scanf("%d%d", &n, &m))
    {
        build(1, 1, n);
        memset(start, -1, sizeof(start));
        memset(end, -1, sizeof(end));
        #ifdef DEBUG
        printf("\n\nBuild\n");
        printTree();
        printMemory();
        #endif // DEBUG
        for (int i = 1; i <= m; ++i)
        {
            scanf("%s", op);
            switch (*op)
            {
            case 'R':
                update(1, 1, n, -1);
                printf("Reset Now\n");
                break;
            case 'N':
                scanf("%d", &len);
                x = queryFree(1, len);
                if (-1 == x)
                {
                    printf("Reject New\n");
                }
                else
                {
                    start[i] = x;
                    end[i] = x + len - 1;
                    update(1, start[i], end[i], i);
                    printf("New at %d\n", x);
                }
                break;
            case 'G':
                scanf("%d", &x);
                x = queryKth(1, x);
                if (-1 == x)
                {
                    printf("Reject Get\n");
                }
                else
                {
                    printf("Get at %d\n", start[x]);
                }
                break;
            case 'F':
                scanf("%d", &x);
                x = queryPos(1, x);
                if (-1 == x)
                {
                    printf("Reject Free\n");
                }
                else
                {
                    update(1, start[x], end[x], -1);
                    printf("Free from %d to %d\n", start[x], end[x]);
                }
                break;
            }
            #ifdef DEBUG
            printTree();
            printMemory();
            #endif // DEBUG
        }
        putchar('\n');
    }
    return 0;
}
