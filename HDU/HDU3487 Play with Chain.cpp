#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 300000 + 10;

class Splay
{
public:
    Splay()
    {
    }
    void init(int n)
    {
        this->n = n;
        root = 0;
        nodeNum = 0;
        insert(0, n + 1);
    }
    void cut(int a, int b, int c)
    {
        int indexL = find(a - 1, -1);
        int indexR = find(b + 1, root);
        int subTree = node[indexR].child[LEFT];
        node[indexR].child[LEFT] = -1;
        pushUp(indexR);
        pushUp(indexL);
        indexL = find(c, -1);
        indexR = find(c + 1, root);
        node[subTree].parent = indexR;
        node[indexR].child[LEFT] = subTree;
        pushUp(indexR);
        pushUp(indexL);
    }
    void flip(int a, int b)
    {
        int indexL = find(a - 1, -1);
        int indexR = find(b + 1, root);
        int subTree = node[indexR].child[LEFT];
        node[subTree].reverse ^= true;
    }
    void print()
    {
        first = true;
        print(root);
        putchar('\n');
    }
private:
    enum Dir
    {
        LEFT = 0,
        RIGHT = 1
    };
    struct Node
    {
        int parent;
        int child[2];
        int value;
        int size;
        bool reverse;
    } node[MAXN];
    int nodeNum, root, n;
    bool first;
    void initNode(int value)
    {
        node[nodeNum].parent = -1;
        node[nodeNum].child[LEFT] = -1;
        node[nodeNum].child[RIGHT] = -1;
        node[nodeNum].value = value;
        node[nodeNum].size = 1;
        node[nodeNum].reverse = false;
    }
    void pushDown(int index)
    {
        if (node[index].reverse)
        {
            int& left = node[index].child[LEFT];
            int& right = node[index].child[RIGHT];
            if (-1 != left)
            {
                node[left].reverse ^= true;
            }
            if (-1 != right)
            {
                node[right].reverse ^= true;
            }
            swap(left, right);
            node[index].reverse = false;
        }
    }
    void pushUp(int index)
    {
        node[index].size = 1;
        node[index].size += getChildNum(index, LEFT);
        node[index].size += getChildNum(index, RIGHT);
    }
    int getChildNum(int index, Dir dir)
    {
        int child = node[index].child[dir];
        if (-1 == child)
        {
            return 0;
        }
        return node[child].size;
    }
    int insert(int left, int right, int parent = -1)
    {
        int mid = (left + right) >> 1;
        initNode(mid);
        node[nodeNum].parent = parent;
        int index = nodeNum++;
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
        while (k != getChildNum(index, LEFT))
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
            if (-1 != ancestor)
            {
                pushDown(ancestor);
            }
            pushDown(parent);
            pushDown(index);
            int dirI = node[parent].child[LEFT] == index;
            if (ancestor == head)
            {
                rotate(index, dirI);
            }
            else
            {
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
    void print(int index)
    {
        if (-1 == index)
        {
            return;
        }
        pushDown(index);
        print(node[index].child[LEFT]);
        if (node[index].value >= 1 && node[index].value <= n)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                putchar(' ');
            }
            printf("%d", node[index].value);
        }
        print(node[index].child[RIGHT]);
    }
} splay;

int main()
{
    int n, m;
    char op[12];
    int a, b, c;
    while (scanf("%d%d", &n, &m), n + 1 || m + 1)
    {
        splay.init(n);
        while (m--)
        {
            scanf("%s%d%d", op, &a, &b);
            if (*op == 'C')
            {
                scanf("%d", &c);
                splay.cut(a, b, c);
            }
            else
            {
                splay.flip(a, b);
            }
        }
        splay.print();
    }
    return 0;
}
