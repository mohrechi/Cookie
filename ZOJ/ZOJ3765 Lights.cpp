#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
const int MAXQ = 100000 + 10;

#ifndef ONLINE_JUDGE
    #define DEBUG
#endif

int gcd(int a, int b)
{
    return 0 == b ? a : gcd(b, a % b);
}

class Splay
{
public:
    Splay()
    {
    }
    void build(int value[], int status[], int n)
    {
        root = 0;
        nodeNum = 0;
        value[0] = value[n + 1] = -1;
        status[0] = status[n + 1] = -1;
        insert(value, status, 0, n + 1, -1);
    }
    void query(int L, int R, int status)
    {
        int indexL = find(L - 1, -1);
        int indexR = find(R + 1, indexL);
        int child = node[indexR].child[LEFT];
        printf("%d\n", node[child].divisor[status]);
    }
    void insert(int i, int value, int status)
    {
        int indexL = find(i, -1);
        int indexR = find(i + 1, indexL);
        initNode(value, status);
        node[indexR].child[LEFT] = nodeNum;
        node[nodeNum++].parent = indexR;
        pushUp(indexR);
        pushUp(indexL);
    }
    void remove(int i)
    {
        int indexL = find(i - 1, -1);
        int indexR = find(i + 1, indexL);
        node[indexR].child[LEFT] = -1;
        pushUp(indexR);
        pushUp(indexL);
    }
    void reverse(int i)
    {
        int index = find(i, -1);
        node[index].status ^= 1;
        pushUp(index);
    }
    void modify(int i, int x)
    {
        int index = find(i, -1);
        node[index].value = x;
        pushUp(index);
    }
    #ifdef DEBUG
    void print(int index = -2, int space = 0)
    {
        if (-1 == index)
        {
            return;
        }
        if (-2 == index)
        {
            index = root;
        }
        if (0 == space)
        {
            puts("===== Splay Debug =====");
        }
        print(node[index].child[RIGHT], space + 2);
        for (int i = 0; i < space; ++i)
        {
            putchar(' ');
        }
        printf("%d %d: %d %d\n", node[index].value, node[index].status, node[index].divisor[0], node[index].divisor[1]);
        print(node[index].child[LEFT], space + 2);
        if (0 == space)
        {
            puts("=======================");
        }
    }
    #endif // DEBUG
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
        int status;
        int size;
        int divisor[2];
    } node[MAXN + MAXQ];
    int nodeNum, root;
    void initNode(int value, int status)
    {
        node[nodeNum].parent = -1;
        node[nodeNum].child[LEFT] = -1;
        node[nodeNum].child[RIGHT] = -1;
        node[nodeNum].value = value;
        node[nodeNum].status = status;
        node[nodeNum].size = 1;
        if (0 == status)
        {
            node[nodeNum].divisor[0] = value;
            node[nodeNum].divisor[1] = -1;
        }
        else
        {
            node[nodeNum].divisor[0] = -1;
            node[nodeNum].divisor[1] = value;
        }
    }
    inline int getChildNum(int index, Dir dir)
    {
        int child = node[index].child[dir];
        if (-1 == child)
        {
            return 0;
        }
        return node[child].size;
    }
    inline int getChildDivisor(int index, Dir dir, int status)
    {
        int child = node[index].child[dir];
        if (-1 == child)
        {
            return -1;
        }
        return node[child].divisor[status];
    }
    void pushUp(int index)
    {
        node[index].size = 1;
        node[index].size += getChildNum(index, LEFT);
        node[index].size += getChildNum(index, RIGHT);
        int l = getChildDivisor(index, LEFT, 0);
        int r = getChildDivisor(index, RIGHT, 0);
        int g = -1 == l ? (-1 == r ? -1 : r) : (-1 == r ? l : gcd(l, r));
        node[index].divisor[0] = 0 == node[index].status ? (-1 == g ? node[index].value : gcd(node[index].value, g)) : g;
        l = getChildDivisor(index, LEFT, 1);
        r = getChildDivisor(index, RIGHT, 1);
        g = -1 == l ? (-1 == r ? -1 : r) : (-1 == r ? l : gcd(l, r));
        node[index].divisor[1] = 1 == node[index].status ? (-1 == g ? node[index].value : gcd(node[index].value, g)) : g;
    }
    int insert(int value[], int status[], int left, int right, int parent)
    {
        int mid = (left + right) >> 1;
        initNode(value[mid], status[mid]);
        node[nodeNum].parent = parent;
        int index = nodeNum++;
        if (mid - 1 >= left)
        {
            node[index].child[LEFT] = insert(value, status, left, mid - 1, index);
        }
        if (right >= mid + 1)
        {
            node[index].child[RIGHT] = insert(value, status, mid + 1, right, index);
        }
        pushUp(index);
        return index;
    }
    int find(int k, int head)
    {
        int index = root;
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
} splay;

int n, q;
int value[MAXN], light[MAXN];

int main()
{
    char op[4];
    while (~scanf("%d%d", &n, &q))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &value[i], &light[i]);
        }
        splay.build(value, light, n);
        #ifdef DEBUG
        splay.print();
        #endif // DEBUG
        int L, R, i, x, status;
        while (q--)
        {
            scanf("%s", op);
            switch (*op)
            {
            case 'Q':
                scanf("%d%d%d", &L, &R, &status);
                splay.query(L, R, status);
                break;
            case 'I':
                scanf("%d%d%d", &i, &x, &status);
                splay.insert(i, x, status);
                break;
            case 'D':
                scanf("%d", &i);
                splay.remove(i);
                break;
            case 'R':
                scanf("%d", &i);
                splay.reverse(i);
                break;
            case 'M':
                scanf("%d%d", &i, &x);
                splay.modify(i, x);
                break;
            }
            #ifdef DEBUG
            splay.print();
            #endif // DEBUG
        }
    }
    return 0;
}
