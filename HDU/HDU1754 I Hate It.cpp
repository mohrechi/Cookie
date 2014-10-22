#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 200000 + 10;
const int MAXM = 5000 + 10;

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
        insert(0, 0);
        insert(1, 0);
    }
    void insert(int pos, int value)
    {
        if (-1 == root)
        {
            initNode(pos, value);
            root = nodeNum;
            ++nodeNum;
            return;
        }
        node[1].pos = pos + 1;
        int index = root;
        while (true)
        {
            int dir = node[index].pos < pos;
            if (-1 == node[index].child[dir])
            {
                node[index].child[dir] = nodeNum;
                break;
            }
            else
            {
                index = node[index].child[dir];
            }
        }
        initNode(pos, value);
        node[nodeNum].parent = index;
        ++nodeNum;
        while (index != -1)
        {
            pushUp(index);
            index = node[index].parent;
        }
    }
    void insert(int value[], int l, int r)
    {
        if (l > r)
        {
            return;
        }
        int mid = (l + r) >> 1;
        insert(mid, value[mid]);
        insert(value, l, mid - 1);
        insert(value, mid + 1, r);
    }
    int query(int l, int r)
    {
        int indexL = find(l - 1, -1);
        int indexR = find(r + 1, root);
        splay(indexR, root);
        return node[node[indexR].child[LEFT]].max;
    }
    void update(int pos, int value)
    {
        int index = find(pos, -1);
        node[index].value = value;
        node[index].max = max(node[index].max, value);
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
        int pos;
        int value;
        int max;
    } node[MAXN];
    int nodeNum, root;
    void initNode(int pos, int value)
    {
        node[nodeNum].parent = -1;
        node[nodeNum].child[LEFT] = -1;
        node[nodeNum].child[RIGHT] = -1;
        node[nodeNum].pos = pos;
        node[nodeNum].value = value;
        node[nodeNum].max = value;
    }
    int find(int pos, int head)
    {
        int index = root;
        while (pos != node[index].pos)
        {
            index = node[index].child[node[index].pos < pos];
        }
        splay(index, head);
        return index;
    }
    inline int getChildMax(int index, int dir)
    {
        if (-1 == node[index].child[dir])
        {
            return 0;
        }
        return node[node[index].child[dir]].max;
    }
    void pushUp(int index)
    {
        node[index].max = max(getChildMax(index, LEFT), getChildMax(index, RIGHT));
        node[index].max = max(node[index].max, node[index].value);
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

int score[MAXN];

int main()
{
    int N, M;
    int a, b;
    char op[10];
    while (~scanf("%d%d", &N, &M))
    {
        splay.clear();
        for (int i = 1; i <= N; ++i)
        {
            scanf("%d", &score[i]);
        }
        splay.insert(score, 1, N);
        for (int i = 0; i < M; ++i)
        {
            scanf("%s%d%d", op, &a, &b);
            if ('Q' == op[0])
            {
                printf("%d\n", splay.query(a, b));
            }
            else
            {
                splay.update(a, b);
            }
        }
    }
    return 0;
}
