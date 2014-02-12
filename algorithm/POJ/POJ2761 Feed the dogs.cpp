//#define METHOD_SPLAY_POINTER
#define METHOD_SPLAY_INDEX

#ifdef METHOD_SPLAY_POINTER
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int MAXM = 50005;
const int INF = 0x7FFFFFFF;

class SplayTree
{
public:
    SplayTree()
    {
        nil = &_nil;
        _nil.value = 0;
        _nil.size = 0;
        _nil.parent = nil;
        _nil.child[LEFT] = nil;
        _nil.child[RIGHT] = nil;
    }

    inline void clear()
    {
        nodeNumber = 0;
        root = nil;
        insert(-INF);
        insert(INF);
    }

    inline void insert(const int value)
    {
        if(root == nil)
        {
            root = newNode(nil, value);
            return;
        }
        Node *x = root;
        while(true)
        {
            int dir = x->value < value;
            if(x->child[dir] == nil)
            {
                x->child[dir] = newNode(x, value);
                update(x);
                splay(x->child[dir], nil);
                return;
            }
            else
            {
                x = x->child[dir];
            }
        }
    }

    inline void remove(const int value)
    {
        int k = find(value);
        find(k - 1, nil);
        find(k + 1, root);
        root->child[RIGHT]->child[LEFT] = nil;
        update(root->child[RIGHT]);
        update(root);
    }

    inline int getKth(const int k)
    {
        find(k + 1, nil);
        return root->value;
    }

    inline void print()
    {
        printf("Splay Tree: \n");
        print(root);
        printf("\n");
    }
private:
    static const int LEFT = 0;
    static const int RIGHT = 1;
    struct Node
    {
        int value, size;
        Node *parent, *child[2];
    } _nil, node[MAXN];
    int nodeNumber;
    Node *root, *nil;

    inline Node *newNode(Node *parent, const int value)
    {
        node[nodeNumber].value = value;
        node[nodeNumber].size = 1;
        node[nodeNumber].parent = parent;
        node[nodeNumber].child[LEFT] = nil;
        node[nodeNumber].child[RIGHT] = nil;
        return &node[nodeNumber++];
    }

    inline void update(Node *x)
    {
        if(x == nil)
        {
            return;
        }
        x->size = x->child[LEFT]->size + x->child[RIGHT]->size + 1;
    }

    inline void rotate(Node *x, const int dir)
    {
        Node *p = x->parent;
        p->child[!dir] = x->child[dir];
        p->child[!dir]->parent = p;
        x->child[dir] = p;
        x->parent = p->parent;
        if(p->parent->child[LEFT] == p)
        {
            p->parent->child[LEFT] = x;
        }
        else
        {
            p->parent->child[RIGHT] = x;
        }
        p->parent = x;
        update(p);
        update(x);
        if(root == p)
        {
            root = x;
        }
    }

    inline void splay(Node *x, Node *y)
    {
        while(x->parent != y)
        {
            if(x->parent->parent == y)
            {
                if(x->parent->child[LEFT] == x)
                {
                    rotate(x, RIGHT);
                }
                else
                {
                    rotate(x, LEFT);
                }
            }
            else if(x->parent->parent->child[LEFT] == x->parent)
            {
                if(x->parent->child[LEFT] == x)
                {
                    rotate(x->parent, RIGHT);
                    rotate(x, RIGHT);
                }
                else
                {
                    rotate(x, LEFT);
                    rotate(x, RIGHT);
                }
            }
            else
            {
                if(x->parent->child[RIGHT] == x)
                {
                    rotate(x->parent, LEFT);
                    rotate(x, LEFT);
                }
                else
                {
                    rotate(x, RIGHT);
                    rotate(x, LEFT);
                }
            }
            update(x);
        }
    }

    inline void find(int k, Node *y)
    {
        Node *x = root;
        while(k != x->child[LEFT]->size + 1)
        {
            if(k <= x->child[LEFT]->size)
            {
                x = x->child[LEFT];
            }
            else
            {
                k -= x->child[LEFT]->size + 1;
                x = x->child[RIGHT];
            }
        }
        splay(x, y);
    }

    inline int find(const int value)
    {
        Node *x = root;
        int count = 0;
        while(true)
        {
            if(x->value == value)
            {
                return count + x->size - x->child[RIGHT]->size;
            }
            else if(x->value > value)
            {
                x = x->child[LEFT];
            }
            else
            {
                count += x->size - x->child[RIGHT]->size;
                x = x->child[RIGHT];
            }
        }
    }

    inline void print(Node *x)
    {
        if(x == nil)
        {
            return;
        }
        printf("%d: %d %d %d\n", x->value, x->child[LEFT]->value, x->child[RIGHT]->value, x->size);
        print(x->child[LEFT]);
        print(x->child[RIGHT]);
    }
} splay;

struct Interval
{
    int a, b, k, index;
    bool operator < (const Interval &interval) const
    {
        return b < interval.b;
    }
} interval[MAXM];
int pretty[MAXN];
int ans[MAXM];

int main()
{
    int n, m;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d", &pretty[i]);
        }
        for(int i=0;i<m;++i)
        {
            scanf("%d%d%d", &interval[i].a, &interval[i].b, &interval[i].k);
            interval[i].index = i;
        }
        sort(interval, interval + m);
        splay.clear();
        int a = 1, b = 0;
        for(int i=0;i<m;++i)
        {
            for(int j=a;j<interval[i].a && j<=b;++j)
            {
                splay.remove(pretty[j]);
            }
            for(int j=max(interval[i].a, b+1);j<=interval[i].b;++j)
            {
                splay.insert(pretty[j]);
            }
            a = interval[i].a;
            b = interval[i].b;
            ans[interval[i].index] = splay.getKth(interval[i].k);
        }
        for(int i=0;i<m;++i)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
#endif // METHOD_SPLAY_POINTER
#ifdef METHOD_SPLAY_INDEX
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100001 + 10;
const int MAXM = 50001 + 10;
const int INF = 0x7fffffff;

class Splay
{
public:
    Splay()
    {
        clear();
    }
    void clear()
    {
        root = -1;
        nodeNum = 0;
        insert(-INF, root);
        insert(INF, root);
    }
    void insert(int value)
    {
        insert(value, root);
    }
    void remove(int value)
    {
        int k = getK(value, root);
        int indexL = query(k - 1, root);
        splay(indexL, -1);
        int indexR = query(k + 1, root);
        splay(indexR, indexL);
        node[indexR].left = -1;
        update(indexR);
        update(indexL);
    }
    int query(int k)
    {
        int index = query(k + 1, root);
        return node[index].value;
    }
private:
    struct TreeNode
    {
        int parent;
        int left, right;
        int value;
        int size;
    } node[MAXN];
    int nodeNum, root;
    void initNode(int value)
    {
        node[nodeNum].parent = -1;
        node[nodeNum].left = -1;
        node[nodeNum].right = -1;
        node[nodeNum].value = value;
        node[nodeNum].size = 1;
    }
    int getLeftNum(int index)
    {
        if (-1 == node[index].left)
        {
            return 0;
        }
        return node[node[index].left].size;
    }
    int getRightNum(int index)
    {
        if (-1 == node[index].right)
        {
            return 0;
        }
        return node[node[index].right].size;
    }
    void update(int index)
    {
        node[index].size = 1;
        node[index].size += getLeftNum(index);
        node[index].size += getRightNum(index);
    }
    void insert(int value, int index)
    {
        if (-1 == root)
        {
            root = nodeNum;
            initNode(value);
            ++nodeNum;
            return;
        }
        while (true)
        {
            if (value < node[index].value)
            {
                if (-1 == node[index].left)
                {
                    node[index].left = nodeNum;
                    break;
                }
                else
                {
                    index = node[index].left;
                }
            }
            else
            {
                if (-1 == node[index].right)
                {
                    node[index].right = nodeNum;
                    break;
                }
                else
                {
                    index = node[index].right;
                }
            }
        }
        initNode(value);
        node[nodeNum].parent = index;
        splay(nodeNum, root);
        ++nodeNum;
    }
    int query(int k, int index)
    {
        while (k != getLeftNum(index) + 1)
        {
            if (k <= getLeftNum(index))
            {
                index = node[index].left;
            }
            else
            {
                k -= getLeftNum(index) + 1;
                index = node[index].right;
            }
        }
        return index;
    }
    int getK(int value, int index, int sum = 1)
    {
        while (value != node[index].value)
        {
            if (value < node[index].value)
            {
                index = node[index].left;
            }
            else
            {
                sum += getLeftNum(index) + 1;
                index = node[index].right;
            }
        }
        return sum + getLeftNum(index);
    }
    void rotateLeft(int index)
    {
        int left = node[index].left;
        int parent = node[index].parent;
        int ancestor = node[parent].parent;
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
        update(parent);
        update(index);
    }
    void rotateRight(int index)
    {
        int right = node[index].right;
        int parent = node[index].parent;
        int ancestor = node[parent].parent;
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
        update(parent);
        update(index);
    }
    void splay(int index, int pos)
    {
        while (node[index].parent != pos)
        {
            int parent = node[index].parent;
            int ancestor = node[parent].parent;
            if (ancestor == pos)
            {
                if (node[parent].left == index)
                {
                    rotateRight(index);
                }
                else
                {
                    rotateLeft(index);
                }
            }
            else
            {
                if (node[ancestor].left == parent)
                {
                    if (node[parent].left == index)
                    {
                        rotateRight(parent);
                        rotateRight(index);
                    }
                    else
                    {
                        rotateLeft(index);
                        rotateRight(index);
                    }
                }
                else
                {
                    if (node[parent].right == index)
                    {
                        rotateLeft(parent);
                        rotateLeft(index);
                    }
                    else
                    {
                        rotateRight(index);
                        rotateLeft(index);
                    }
                }
            }
        }
    }
};

int n, m;
int a[MAXN];
struct Query
{
    int left;
    int right;
    int k;
    int index;
    bool operator <(const Query &query) const
    {
        return right < query.right;
    }
} query[MAXM];
int ans[MAXM];
Splay splay;

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < m; ++i)
        {
            query[i].index = i;
            scanf("%d%d%d", &query[i].left, &query[i].right, &query[i].k);
        }
        sort(query, query + m);
        int left = 1, right = 0;
        splay.clear();
        for (int i = 0; i < m; ++i)
        {
            for (int j = left; j <= right && j < query[i].left; ++j)
            {
                splay.remove(a[j]);
            }
            left = query[i].left;
            for (int j = max(right + 1, query[i].left); j <= query[i].right; ++j)
            {
                splay.insert(a[j]);
            }
            right = query[i].right;
            ans[query[i].index] = splay.query(query[i].k);
        }
        for (int i = 0; i < m; ++i)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
#endif
