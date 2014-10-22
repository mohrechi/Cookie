#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50000 + 10;

//#define DEBUG

class SplayForest
{
public:
    SplayForest()
    {
    }
    void clear(int n)
    {
        this->n = n;
    }
    void build(int x, int y)
    {
        initNode(x, x);
        initNode(x + n, x);
        node[x].child[RIGHT] = x + n;
        node[x + n].parent = x;
        if (y)
        {
            splay(y, -1);
            int right = node[y].child[RIGHT];
            while (-1 != node[right].child[LEFT])
            {
                right = node[right].child[LEFT];
            }
            splay(right, y);
            node[right].child[LEFT] = x;
            node[x].parent = right;
        }
    }
    void move(int x, int y)
    {
        if (x == y)
        {
            return;
        }
        splay(x, -1);
        splay(x + n, x);
        if (y)
        {
            int index = y;
            while (-1 != node[index].parent)
            {
                if (index == node[x + n].child[LEFT])
                {
                    return;
                }
                index = node[index].parent;
            }
        }
        int left = node[x].child[LEFT];
        int right = node[x + n].child[RIGHT];
        node[x].child[LEFT] = -1;
        node[x + n].child[RIGHT] = -1;
        node[left].parent = -1;
        node[right].parent = -1;
        if (-1 != left)
        {
            node[left].parent = -1;
        }
        if (-1 != right)
        {
            node[right].parent = -1;
            if (-1 != left)
            {
                while (-1 != node[right].child[LEFT])
                {
                    right = node[right].child[LEFT];
                }
                node[right].child[LEFT] = left;
                node[left].parent = right;
            }
        }
        if (y)
        {
            splay(y, -1);
            right = node[y].child[RIGHT];
            while (-1 != node[right].child[LEFT])
            {
                right = node[right].child[LEFT];
            }
            splay(right, y);
            node[right].child[LEFT] = x;
            node[x].parent = right;
        }
    }
    int query(int x)
    {
        splay(x, -1);
        while (-1 != node[x].child[LEFT])
        {
            x = node[x].child[LEFT];
        }
        return x;
    }
    #ifdef DEBUG
    void print()
    {
        printf("=== Forest ===\n");
        for (int i = 1; i <= n; ++i)
        {
            if (-1 == node[i].parent)
            {
                print(i);
            }
            if (-1 == node[i + n].parent)
            {
                print(i + n);
            }
        }
        printf("==============\n\n");
    }
    void print(int index, int space = 0)
    {
        if (-1 == index)
        {
            return;
        }
        if (0 == space)
        {
            printf("--- Splay ---\n");
        }
        print(node[index].child[RIGHT], space + 2);
        for (int i = 0; i < space; ++i)
        {
            printf(" ");
        }
        printf("%d\n", index <= n ? index : index - n);
        print(node[index].child[LEFT], space + 2);
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
    } node[MAXN * 2];
    int n;
    void initNode(int index, int value)
    {
        node[index].parent = -1;
        node[index].child[LEFT] = -1;
        node[index].child[RIGHT] = -1;
    }
    void rotate(int index, int dir)
    {
        int child = node[index].child[dir];
        int parent = node[index].parent;
        int ancestor = node[parent].parent;
        if (-1 != ancestor)
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
} forest;

int n, m;
int parent[MAXN];
bool visit[MAXN];

void build(int index)
{
    if (0 != parent[index] && !visit[parent[index]])
    {
        build(parent[index]);
    }
    forest.build(index, parent[index]);
    visit[index] = true;
}

int main()
{
    int x, y, t = 0;
    char op[12];
    while (~scanf("%d", &n))
    {
        if (t++)
        {
            putchar('\n');
        }
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &parent[i]);
        }
        memset(visit, false, sizeof(visit));
        forest.clear(n);
        for (int i = 1; i <= n; ++i)
        {
            if (!visit[i])
            {
                build(i);
            }
        }
        #ifdef DEBUG
        printf("Build: \n");
        forest.print();
        #endif // DEBUG
        scanf("%d", &m);
        while (m--)
        {
            scanf("%s%d", op, &x);
            if ('M' == *op)
            {
                scanf("%d", &y);
                forest.move(x, y);
                #ifdef DEBUG
                forest.print();
                #endif
            }
            else
            {
                printf("%d\n", forest.query(x));
            }
        }
    }
    return 0;
}
