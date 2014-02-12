#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;

//#define DEBUG

class Splay
{
public:
    Splay()
    {
    }
    void clear(int n)
    {
        root = 0;
        nodeNum = 0;
        insert(0, n + 1);
    }
    int query(int pos)
    {
        int index = posIndex[pos];
        splay(index, -1);
        int k = getChildNum(root, LEFT);
        int indexL = find(k, -1);
        int indexR = find(k + 2, root);
        node[indexR].child[LEFT] = -1;
        pushUp(indexR);
        pushUp(indexL);
        splay(posIndex[0], -1);
        splay(indexR, root);
        node[node[indexR].child[LEFT]].reverse ^= true;
        return k;
    }
    #ifdef DEBUG
    void print(int index = -2, int space = 0)
    {
        if (-2 == index)
        {
            index = root;
            puts("Splay");
        }
        if (-1 == index)
        {
            return;
        }
        for (int i = 0; i < space; ++i)
        {
            putchar(' ');
        }
        for (int i = 0; ; ++i)
        {
            if (posIndex[i] == index)
            {
                printf("%d: ", i);
                break;
            }
        }
        printf("%d %d\n", node[index].size, node[index].reverse);
        print(node[index].child[LEFT], space + 4);
        print(node[index].child[RIGHT], space + 4);
    }
    void printLine()
    {
        printf("\tLine: ");
        printLine(root, false);
        putchar('\n');
    }
    void printLine(int index, bool reverse)
    {
        if (-1 == index)
        {
            return;
        }
        bool r = node[index].reverse ^ reverse;
        if (r)
        {
            printLine(node[index].child[RIGHT], r);
            for (int i = 0; ; ++i)
            {
                if (posIndex[i] == index)
                {
                    printf("%d ", i);
                    break;
                }
            }
            printLine(node[index].child[LEFT], r);
        }
        else
        {
            printLine(node[index].child[LEFT], r);
            for (int i = 0; ; ++i)
            {
                if (posIndex[i] == index)
                {
                    printf("%d ", i);
                    break;
                }
            }
            printLine(node[index].child[RIGHT], r);
        }
    }
    #endif
private:
    enum Dir
    {
        LEFT = 0,
        RIGHT = 1
    };
    struct TreeNode
    {
        int parent;
        int child[2];
        int size;
        bool reverse;
    } node[MAXN];
    int posIndex[MAXN];
    int nodeNum, root;
    void initNode()
    {
        node[nodeNum].parent = -1;
        node[nodeNum].child[LEFT] = -1;
        node[nodeNum].child[RIGHT] = -1;
        node[nodeNum].size = 1;
        node[nodeNum].reverse = false;
    }
    inline int getChildNum(int index, int dir)
    {
        if (-1 == node[index].child[dir])
        {
            return 0;
        }
        return node[node[index].child[dir]].size;
    }
    void pushUp(int index)
    {
        node[index].size = 1;
        node[index].size += getChildNum(index, LEFT);
        node[index].size += getChildNum(index, RIGHT);
    }
    void pushDown(int index)
    {
        if (node[index].reverse)
        {
            int l = node[index].child[LEFT];
            int r = node[index].child[RIGHT];
            if (-1 != l)
            {
                node[l].reverse ^= true;
            }
            if (-1 != r)
            {
                node[r].reverse ^= true;
            }
            swap(node[index].child[LEFT], node[index].child[RIGHT]);
            node[index].reverse = false;
        }
    }
    int insert(int left, int right, int parent = -1)
    {
        int mid = (left + right) >> 1;
        initNode();
        node[nodeNum].parent = parent;
        int index = nodeNum++;
        posIndex[mid] = index;
        if (mid - 1 >= left)
        {
            node[index].child[LEFT] = insert(left, mid - 1, index);
        }
        if (right >= mid + 1)
        {
            node[index].child[RIGHT] = insert(mid + 1, right, index);
        }
        pushUp(index);
        return index;
    }
    int find(int k, int head)
    {
        int index = root;
        pushDown(index);
        while (k != getChildNum(index, LEFT) + 1)
        {
            if (k <= getChildNum(index, LEFT))
            {
                index = node[index].child[LEFT];
            }
            else
            {
                k -= getChildNum(index, LEFT) + 1;
                index = node[index].child[RIGHT];
            }
            pushDown(index);
        }
        splay(index, head);
        return index;
    }
    void rotate(int index, int dir)
    {
        int child = node[index].child[dir];
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
            node[ancestor].child[node[ancestor].child[RIGHT] == parent] = index;
        }
        node[index].parent = ancestor;
        node[index].child[dir] = parent;
        node[parent].parent = index;
        node[parent].child[!dir] = child;
        if (-1 != child)
        {
            node[child].parent = parent;
        }
        pushUp(parent);
        pushUp(index);
    }
    void splay(int index, int head)
    {
        while (node[index].parent != head)
        {
            int parent = node[index].parent;
            int ancestor = node[parent].parent;
            if (ancestor == head)
            {
                pushDown(parent);
                pushDown(index);
                int dirI = node[parent].child[LEFT] == index;
                rotate(index, dirI);
            }
            else
            {
                pushDown(ancestor);
                pushDown(parent);
                pushDown(index);
                int dirI = node[parent].child[LEFT] == index;
                int dirP = node[ancestor].child[LEFT] == parent;
                if (dirI == dirP)
                {
                    rotate(parent, dirP);
                    rotate(index, dirI);
                }
                else
                {
                    rotate(index, dirI);
                    rotate(index, dirP);
                }
            }
        }
    }
};

int n;
struct Node
{
    int index;
    int value;
    bool operator <(const Node &node) const
    {
        if (value == node.value)
        {
            return index < node.index;
        }
        return value < node.value;
    }
} node[MAXN];
Splay splay;

int main()
{
    while (scanf("%d", &n), n)
    {
        for (int i = 0; i < n; ++i)
        {
            node[i].index = i + 1;
            scanf("%d", &node[i].value);
        }
        sort(node, node + n);
        splay.clear(n);
        for (int i = 0; i < n; ++i)
        {
            if (i)
            {
                putchar(' ');
            }
            int pos = splay.query(node[i].index);
            printf("%d", i + pos);
        }
        printf("\n");
    }
    return 0;
}
