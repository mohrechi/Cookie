#define METHOD_SEGMENT_TREE
//#define METHOD_SPLAY

#ifdef METHOD_SEGMENT_TREE
#include <cstdio>
#include <cstring>
static const int MAXN = 100001;

int n, m;
struct TreeNode
{
    int l, r;
    long long sum, update;
}node[MAXN * 3];
long long num[MAXN];

inline int max(int x, int y)
{
    return x > y ? x : y;
}

inline int left(int x)
{
    return x << 1;
}

inline int right(int x)
{
    return (x << 1) + 1;
}

inline int midium(int x, int y)
{
    return (x + y) >> 1;
}

inline int nodeLength(int x)
{
    return node[x].r - node[x].l + 1;
}

void createTree(int x, int l, int r)
{
    node[x].l = l;
    node[x].r = r;
    node[x].update = 0;
    if(l == r)
    {
        node[x].sum = num[l];
    }
    else
    {
        int mid = midium(l, r);
        createTree(left(x), l, mid);
        createTree(right(x), mid + 1, r);
        node[x].sum = node[left(x)].sum + node[right(x)].sum;
    }
}

void updateTreeNode(int x)
{
    if(node[x].update)
    {
        node[left(x)].sum += node[x].update * nodeLength(left(x));
        node[left(x)].update += node[x].update;
        node[right(x)].sum += node[x].update * nodeLength(right(x));
        node[right(x)].update += node[x].update;
        node[x].update = 0;
    }
}

void updateTree(int x, int l, int r, int v)
{
    if(node[x].l == l && node[x].r == r)
    {
        node[x].sum += v * nodeLength(x);
        node[x].update += v;
    }
    else
    {
        updateTreeNode(x);
        int mid = midium(node[x].l, node[x].r);
        if(r <= mid)
        {
            updateTree(left(x), l, r, v);
        }
        else if(l > mid)
        {
            updateTree(right(x), l, r, v);
        }
        else
        {
            updateTree(left(x), l, mid, v);
            updateTree(right(x), mid + 1, r, v);
        }
        node[x].sum = node[left(x)].sum + node[right(x)].sum;
    }
}

long long searchTree(int x, int l, int r)
{
    if(node[x].l == l && node[x].r == r)
    {
        return node[x].sum;
    }
    updateTreeNode(x);
    int mid = midium(node[x].l, node[x].r);
    if(r <= mid)
    {
        return searchTree(left(x), l, r);
    }
    else if(l > mid)
    {
        return searchTree(right(x), l, r);
    }
    else
    {
        return searchTree(left(x), l, mid) + searchTree(right(x), mid+1, r);
    }
}

int main()
{
    char op[5];
    int a, b, c;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%lld", &num[i]);
        }
        createTree(1, 1, n);
        while(m--)
        {
            scanf("%s", &op);
            switch(*op)
            {
            case 'Q':
                scanf("%d%d",&a,&b);
                printf("%lld\n", searchTree(1, a, b));
                break;
            case 'C':
                scanf("%d%d%d",&a,&b,&c);
                updateTree(1, a, b, c);
                break;
            }
        }
    }
    return 0;
}
#endif // METHOD_SEGMENT_TREE
#ifdef METHOD_SPLAY
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

//#define DEBUG

class Splay
{
public:
    Splay();
    void clear();
    void addBound(int n);
    void insert(int val[], int n);
    void insert(int val[], int left, int right);
    void update(int l, int r, int val);
    long long query(int l, int r);
    #ifdef DEBUG
    void print(int index = -1, int depth = 0);
    #endif
private:
    struct TreeNode
    {
        int parent;         // The index of parent tree node, the value is -1 if it is root.
        int left, right;    // The indexes of child tree node, the value is -1 if it has no child.
        int posVal;         // The value is used for building binary search tree.
        long long value;
        long long sum;
        long long lazy;
        int num;            // The total number of nodes in the current tree.
    } node[MAXN];
    int nodeNum, root;
    void initNode(int posVal, long long val);
    void insertNode(int posVal, long long val, int index);
    void pushDown(int index);
    void pushUp(int index);
    int find(int posVal, int index);
    void rotateLeft(int index);
    void rotateRight(int index);
    void splay(int index, int pos);
};

Splay::Splay()
{
    clear();
}

void Splay::clear()
{
    root = -1;
    nodeNum = 0;
}

// Add minimum and maximum bound.
void Splay::addBound(int n)
{
    insertNode(0, 0, root);
    insertNode(n + 1, 0, root);
}

void Splay::insert(int val[], int n)
{
    // Make a chain.
    for (int i = 1; i <= n; ++i)
    {
        insertNode(i, val[i], root);
    }
}

void Splay::insert(int val[], int left, int right)
{
    // Make a balanced tree.
    if (left == right)
    {
        insertNode(left, val[left], root);
        return;
    }
    if (left > right)
    {
        return;
    }
    int mid = (left + right) >> 1;
    insertNode(mid, val[mid], root);
    insert(val, left, mid - 1);
    insert(val, mid + 1, right);
}

void Splay::update(int l, int r, int val)
{
    int indexL = find(l - 1, root);
    splay(indexL, -1);
    int indexR = find(r + 1, root);
    splay(indexR, indexL);
    int head = node[indexR].left;
    node[head].value += val;
    node[head].lazy += val;
    node[head].sum += val * node[head].num;
}

long long Splay::query(int l, int r)
{
    int indexL = find(l - 1, root);
    splay(indexL, -1);
    int indexR = find(r + 1, root);
    splay(indexR, indexL);
    int head = node[indexR].left;
    return node[head].sum;
}

void Splay::initNode(int posVal, long long val)
{
    node[nodeNum].parent = -1;
    node[nodeNum].left = -1;
    node[nodeNum].right = -1;
    node[nodeNum].posVal = posVal;
    node[nodeNum].value = val;
    node[nodeNum].sum = val;
    node[nodeNum].lazy = 0;
    node[nodeNum].num = 1;
}

void Splay::insertNode(int posVal, long long val, int index)
{
    if (-1 == root)
    {
        // Insert root node.
        root = nodeNum;
        initNode(posVal, val);
        ++nodeNum;
        return;
    }
    if (posVal < node[index].posVal)
    {
        if (-1 == node[index].left)
        {
            // Add node to left child.
            node[index].left = nodeNum;
            initNode(posVal, val);
            node[nodeNum].parent = index;
            ++nodeNum;
        }
        else
        {
            insertNode(posVal, val, node[index].left);
        }
    }
    else
    {
        if (-1 == node[index].right)
        {
            // Add node to right child.
            node[index].right = nodeNum;
            initNode(posVal, val);
            node[nodeNum].parent = index;
            ++nodeNum;
        }
        else
        {
            insertNode(posVal, val, node[index].right);
        }
    }
    pushUp(index);
}

// Execute lazy.
void Splay::pushDown(int index)
{
    if (node[index].lazy)
    {
        long long lazy = node[index].lazy;
        int left = node[index].left;
        int right = node[index].right;
        if (-1 != left)
        {
            node[left].value += lazy;
            node[left].sum += lazy * node[left].num;
            node[left].lazy += lazy;
        }
        if (-1 != right)
        {
            node[right].value += lazy;
            node[right].sum += lazy * node[right].num;
            node[right].lazy += lazy;
        }
        node[index].lazy = 0;
    }
}

// Update collection values.
void Splay::pushUp(int index)
{
    int left = node[index].left;
    int right = node[index].right;
    node[index].sum = node[index].value;
    node[index].num = 1;
    if (-1 != left)
    {
        node[index].sum += node[left].sum;
        node[index].num += node[left].num;
    }
    if (-1 != right)
    {
        node[index].sum += node[right].sum;
        node[index].num += node[right].num;
    }
}

int Splay::find(int posVal, int index)
{
    if (posVal < node[index].posVal)
    {
        if (-1 == node[index].left)
        {
            return index;
        }
        return find(posVal, node[index].left);
    }
    if (posVal > node[index].posVal)
    {
        if (-1 == node[index].right)
        {
            return index;
        }
        return find(posVal, node[index].right);
    }
    return index;
}

void Splay::rotateLeft(int index)
{
    int left = node[index].left;
    int parent = node[index].parent;
    int ancestor = node[parent].parent;
    pushDown(parent);
    pushDown(index);
    if (-1 == ancestor)
    {
        root = index;
    }
    else
    {
        if (node[ancestor].left == parent)
        {
            node[ancestor].left = index;
        }
        else
        {
            node[ancestor].right = index;
        }
    }
    node[index].parent = ancestor;
    node[index].left = parent;
    node[parent].parent = index;
    node[parent].right = left;
    if (-1 != left)
    {
        node[left].parent = parent;
    }
    pushUp(parent);
    pushUp(index);
}

void Splay::rotateRight(int index)
{
    int right = node[index].right;
    int parent = node[index].parent;
    int ancestor = node[parent].parent;
    pushDown(parent);
    pushDown(index);
    if (-1 == ancestor)
    {
        root = index;
    }
    else
    {
        if (node[ancestor].left == parent)
        {
            node[ancestor].left = index;
        }
        else
        {
            node[ancestor].right = index;
        }
    }
    node[index].parent = ancestor;
    node[index].right = parent;
    node[parent].parent = index;
    node[parent].left = right;
    if (-1 != right)
    {
        node[right].parent = parent;
    }
    pushUp(parent);
    pushUp(index);
}

void Splay::splay(int index, int pos)
{
    while (node[index].parent != pos)
    {
        int parent = node[index].parent;
        if (node[parent].left == index)
        {
            rotateRight(index);
        }
        else
        {
            rotateLeft(index);
        }
    }
}

#ifdef DEBUG
void Splay::print(int index, int depth)
{
    if (-1 == index)
    {
        index = root;
    }
    for (int i = 0; i < depth; ++i)
    {
        printf("  ");
    }
    printf("%d: P %d L %d R %d - P %d V %lld N %d S %lld L %lld\n", index, node[index].parent, node[index].left, node[index].right, node[index].posVal, node[index].value, node[index].num, node[index].sum, node[index].lazy);
    if (-1 != node[index].left)
    {
        print(node[index].left, depth + 1);
    }
    if (-1 != node[index].right)
    {
        print(node[index].right, depth + 1);
    }
}
#endif

int N, Q;
int array[MAXN];
Splay splay;

int main()
{
    int a, b, c;
    char op[10];
    while (~scanf("%d%d", &N, &Q))
    {
        for (int i = 1; i <= N; ++i)
        {
            scanf("%d", &array[i]);
        }
        splay.clear();
        splay.addBound(N);
        //splay.insert(array, N);
        splay.insert(array, 1, N);
        #ifdef DEBUG
        splay.print();
        #endif
        for (int i = 0; i < Q; ++i)
        {
            scanf("%s %d %d", op, &a, &b);
            if ('Q' == op[0])
            {
                printf("%lld\n", splay.query(a, b));
            }
            else
            {
                scanf("%d", &c);
                splay.update(a, b, c);
            }
            #ifdef DEBUG
            splay.print();
            #endif
        }
    }
    return 0;
}
#endif // METHOD_SPLAY
