#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 10;
const int MAXQ = 100000 + 10;
const int INF = 0x3f3f3f3f;

//#define DEBUG

class Splay
{
public:
    Splay()
    {
    }
    void init(int val[], int n)
    {
        val[0] = 0;
        val[n + 1] = 0;
        insert(val, 0, n + 1);
        root = 0;
    }
    void insert(int pos, int val)
    {
        int indexL = find(pos - 1, -1);
        int indexR = find(pos, root);
        initNode(val);
        node[indexR].child[LEFT] = nodeNum;
        node[nodeNum++].parent = indexR;
        pushUp(indexR);
        pushUp(indexL);
    }
    void remove(int pos)
    {
        int indexL = find(pos - 1, -1);
        int indexR = find(pos + 1, root);
        node[indexR].child[LEFT] = -1;
        pushUp(indexR);
        pushUp(indexL);
    }
    void update(int pos, int val)
    {
        int indexL = find(pos - 1, -1);
        int indexR = find(pos + 1, root);
        int child = node[indexR].child[LEFT];
        node[child].value = val;
        pushUp(child);
        pushUp(indexR);
        pushUp(indexL);
    }
    int query(int u, int v)
    {
        int indexL = find(u - 1, -1);
        int indexR = find(v + 1, root);
        int head = node[indexR].child[LEFT];
        int L = node[head].child[LEFT];
        int R = node[head].child[RIGHT];
        int val = node[head].value;
        if (-1 == L)
        {
            if (-1 == R)
            {
                return node[head].value;
            }
            else
            {
                return max(val, max(node[R].opt, val + node[R].maxL));
            }
        }
        else
        {
            if (-1 == R)
            {
                return max(val, max(node[L].opt, val + node[L].maxR));
            }
            else
            {
                return max(val, max(max(node[L].opt, node[R].opt), max(max(node[L].maxR + val, val + node[R].maxL), node[L].maxR + val + node[R].maxL)));
            }
        }
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
            printf("===== Splay =====\n");
            index = root;
        }
        print(node[index].child[RIGHT], space + 2);
        for (int i = 0; i < space; ++i)
        {
            putchar(' ');
        }
        printf("%d: %d %d %d %d\n", node[index].value, node[index].sum, node[index].maxL, node[index].maxR, node[index].opt);
        print(node[index].child[LEFT], space + 2);
        if (0 == space)
        {
            printf("=================\n");
        }
    }
    #endif // DEBUG
private:
    enum Dir
    {
        LEFT = 0, RIGHT = 1
    };
    struct Node
    {
        int parent;
        int child[2];
        int size;
        int value;
        int sum, opt;
        int maxL, maxR;
    } node[MAXN + MAXQ];
    int nodeNum, root;
    inline void initNode(int x)
    {
        node[nodeNum].parent = -1;
        node[nodeNum].child[LEFT] = -1;
        node[nodeNum].child[RIGHT] = -1;
        node[nodeNum].size = 1;
        node[nodeNum].value = x;
        node[nodeNum].sum = x;
        node[nodeNum].maxL = x;
        node[nodeNum].maxR = x;
        node[nodeNum].opt = x;
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
    void pushUp(int x)
    {
        int L = node[x].child[LEFT];
        int R = node[x].child[RIGHT];
        int val = node[x].value;
        node[x].size = 1;
        node[x].size += getChildNum(x, LEFT);
        node[x].size += getChildNum(x, RIGHT);
        if (-1 == L)
        {
            if (-1 == R)
            {
                node[x].sum = node[x].value;
                node[x].maxL = node[x].value;
                node[x].maxR = node[x].value;
                node[x].opt = node[x].value;
            }
            else
            {
                node[x].sum = val + node[R].sum;
                node[x].maxL = max(val, val + node[R].maxL);
                node[x].maxR = max(node[R].maxR, node[R].sum + val);
                node[x].opt = max(val, max(node[R].opt, val + node[R].maxL));
            }
        }
        else
        {
            if (-1 == R)
            {
                node[x].sum = node[L].sum + val;
                node[x].maxL = max(node[L].maxL, node[L].sum + val);
                node[x].maxR = max(val, node[L].maxR + val);
                node[x].opt = max(val, max(node[L].opt, node[L].maxR + val));
            }
            else
            {
                node[x].sum = node[L].sum + val + node[R].sum;
                node[x].maxL = max(node[L].maxL, max(node[L].sum + val, node[L].sum + val + node[R].maxL));
                node[x].maxR = max(node[R].maxR, max(node[R].sum + val, node[R].sum + val + node[L].maxR));
                node[x].opt = max(val, max(max(node[L].opt, node[R].opt), max(max(node[L].maxR + val, val + node[R].maxL), node[L].maxR + val + node[R].maxL)));
            }
        }
    }
    int insert(int val[], int left, int right, int parent = -1)
    {
        int mid = (left + right) >> 1;
        initNode(val[mid]);
        node[nodeNum].parent = parent;
        int index = nodeNum++;
        if (mid - 1 >= left)
        {
            node[index].child[LEFT] = insert(val, left, mid - 1, index);
        }
        if (right >= mid + 1)
        {
            node[index].child[RIGHT] = insert(val, mid + 1, right, index);
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

int n, m;
int val[MAXN];

int main()
{
    int x, y;
    char op[4];
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &val[i]);
        }
        splay.init(val, n);
        #ifdef DEBUG
        splay.print();
        #endif // DEBUG
        scanf("%d", &m);
        while (m--)
        {
            scanf("%s", op);
            switch (*op)
            {
            case 'I':
                scanf("%d%d", &x, &y);
                splay.insert(x, y);
                break;
            case 'D':
                scanf("%d", &x);
                splay.remove(x);
                break;
            case 'R':
                scanf("%d%d", &x, &y);
                splay.update(x, y);
                break;
            case 'Q':
                scanf("%d%d", &x, &y);
                printf("%d\n", splay.query(x, y));
                break;
            }
            #ifdef DEBUG
            splay.print();
            #endif // DEBUG
        }
    }
    return 0;
}
