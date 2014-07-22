#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 100;

class Splay
{
public:
    Splay()
    {
    }
    void init(int n)
    {
        root = 0;
        nodeNum = 0;
        insert(0, n + 1);
    }
    void flip(int a, int b)
    {
        int indexL = find(a - 1, -1);
        int indexR = find(b + 1, root);
        int subTree = node[indexR].child[LEFT];
        node[subTree].reverse ^= true;
    }
    int getKth(int k)
    {
        return node[find(k, -1)].value;
    }
    int getPosition(int val)
    {
        splay(map[val], -1);
        return getChildNum(map[val], LEFT);
    }
    void print(int index = -2, int space = 0)
    {
        if (-1 == index)
        {
            return;
        }
        if (-2 == index)
        {
            index = root;
            printf("Splay: \n");
        }
        pushDown(index);
        print(node[index].child[RIGHT], space + 2);
        for (int i = 0; i < space; ++i)
        {
            putchar(' ');
        }
        printf("%d\n", node[index].value);
        print(node[index].child[LEFT], space + 2);
    }
private:
    enum Dir
    {
        LEFT = 0, RIGHT = 1
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
    int map[MAXN];
    void initNode(int value)
    {
        node[nodeNum].parent = -1;
        node[nodeNum].child[LEFT] = -1;
        node[nodeNum].child[RIGHT] = -1;
        node[nodeNum].value = value;
        node[nodeNum].size = 1;
        node[nodeNum].reverse = false;
        map[value] = nodeNum;
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
            if (k < getChildNum(index, LEFT))
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
} splay;

int main()
{
    int N, Q;
    int a, b, c;
    scanf("%d%d", &N, &Q);
    splay.init(N);
    //splay.print();
    while (Q--)
    {
        scanf("%d%d", &a, &b);
        if (a == 1)
        {
            scanf("%d", &c);
            splay.flip(b, c);
            //splay.print();
        }
        else
        {
            if (a == 2)
            {
                printf("element %d is at position %d\n", b, splay.getPosition(b));
            }
            else
            {
                printf("element at position %d is %d\n", b, splay.getKth(b));
            }
        }
    }
    return 0;
}
