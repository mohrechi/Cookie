#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 2000000;

//#define DEBUG

class Editor
{
public:
    Editor()
    {
        root = 0;
        nodeNum = 0;
        initNode('$');
        nodeNum = 1;
        initNode('$');
        nodeNum = 2;
        node[0].child[RIGHT] = 1;
        node[1].parent = 0;
        node[0].size = 2;
        cursor = 1;
    }
    void insert(int len, char *s)
    {
        int indexL = find(cursor, -1);
        int indexR = find(cursor + 1, indexL);
        int index = insert(s, 0, len - 1);
        node[indexR].child[LEFT] = index;
        node[index].parent = indexR;
        pushUp(indexR);
        pushUp(indexL);
    }
    void remove(int len)
    {
        int indexL = find(cursor, -1);
        int indexR = find(cursor + len + 1, indexL);
        node[indexR].child[LEFT] = -1;
        pushUp(indexR);
        pushUp(indexL);
    }
    void print(int len)
    {
        int indexL = find(cursor, -1);
        int indexR = find(cursor + len + 1, indexL);
        display(node[indexR].child[LEFT]);
        putchar('\n');
    }
    void move(int pos)
    {
        cursor = pos + 1;
    }
    void prev()
    {
        --cursor;
    }
    void next()
    {
        ++cursor;
    }
    #ifdef DEBUG
    void display()
    {
        display(root);
        putchar('\n');
    }
    void printTree(int index = -2, int space = 0)
    {
        if (-1 == index)
        {
            return;
        }
        if (space == 0)
        {
            puts("=============");
            index = root;
        }
        printTree(node[index].child[RIGHT], space + 2);
        for (int i = 0; i < space; ++i)
        {
            putchar(' ');
        }
        printf("%c: %d\n", node[index].ch, node[index].size);
        printTree(node[index].child[LEFT], space + 2);
        if (space == 0)
        {
            puts("=============");
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
        char ch;
    } node[MAXN];
    int nodeNum, root, cursor;
    inline void initNode(char ch)
    {
        node[nodeNum].parent = -1;
        node[nodeNum].child[LEFT] = -1;
        node[nodeNum].child[RIGHT] = -1;
        node[nodeNum].size = 1;
        node[nodeNum].ch = ch;
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
    void pushUp(int index)
    {
        node[index].size = 1;
        node[index].size += getChildNum(index, LEFT);
        node[index].size += getChildNum(index, RIGHT);
    }
    int insert(char *s, int left, int right, int parent = -1)
    {
        int mid = (left + right) >> 1;
        initNode(s[mid]);
        node[nodeNum].parent = parent;
        int index = nodeNum++;
        if (mid - 1 >= left)
        {
            node[index].child[LEFT] = insert(s, left, mid - 1, index);
        }
        if (right >= mid + 1)
        {
            node[index].child[RIGHT] = insert(s, mid + 1, right, index);
        }
        pushUp(index);
        return index;
    }
    int find(int k, int head)
    {
        int index = root;
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
    void display(int index)
    {
        if (-1 == index)
        {
            return;
        }
        display(node[index].child[LEFT]);
        putchar(node[index].ch);
        display(node[index].child[RIGHT]);
    }
} editor;
char s[MAXN];

int main()
{
    int n, m, len;
    char op[20];
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", op);
        switch (*op)
        {
        case 'I':
            scanf("%d", &m);
            len = 0;
            while (len != m)
            {
                s[len] = getchar();
                if (s[len] != '\n')
                {
                    ++len;
                }
            }
            editor.insert(m, s);
            break;
        case 'D':
            scanf("%d", &m);
            editor.remove(m);
            break;
        case 'G':
            scanf("%d", &m);
            editor.print(m);
            break;
        case 'M':
            scanf("%d", &m);
            editor.move(m);
            break;
        case 'P':
            editor.prev();
            break;
        case 'N':
            editor.next();
            break;
        }
        #ifdef DEBUG
        editor.printTree();
        editor.display();
        #endif // DEBUG
    }
    return 0;
}
