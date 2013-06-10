#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;
const int MAXC = 26;
const int MAXL = 55;
const int MAXM = 1000005;

int n;
char word[MAXL];
char str[MAXM];

struct Node
{
    int next[MAXC];
    int count;
    int fail;
} node[MAXN * MAXL];
int nodeNum;

int newNode()
{
    node[nodeNum].count = 0;
    memset(node[nodeNum].next, -1, sizeof(node[nodeNum].next));
    return nodeNum++;
}

void initRoot()
{
    nodeNum = 0;
    newNode();
}

inline int getPos(const char &ch)
{
    return ch - 'a';
}

void insertWord(int index, const char *word)
{
    if (*word == 0)
    {
        ++node[index].count;
        return;
    }
    int pos = getPos(*word);
    int next = node[index].next[pos];
    if (next == -1)
    {
        next = newNode();
        node[index].next[pos] = next;
    }
    insertWord(next, word + 1);
}

int queue[MAXN * MAXL];

void buildAC()
{
    node[0].fail = -1;
    queue[0] = 0;
    int front = 0, rear = 1;
    while (front != rear)
    {
        int u = queue[front];
        for (int i = 0; i < MAXC; ++i)
        {
            if (node[u].next[i] != -1)
            {
                int v = node[u].next[i];
                int fail = node[u].fail;
                while (fail != -1)
                {
                    if (node[fail].next[i] != -1)
                    {
                        node[v].fail = node[fail].next[i];
                        break;
                    }
                    fail = node[fail].fail;
                }
                if (fail == -1)
                {
                    node[v].fail = 0;
                }
                queue[rear++] = v;
            }
        }
        ++front;
    }
}

int searchAC(const char *str)
{
    int res = 0;
    int u = 0;
    for (int i = 0; str[i]; ++i)
    {
        int pos = getPos(str[i]);
        if (node[u].next[pos] == -1)
        {
            int fail = node[u].fail;
            while (fail != -1)
            {
                if (node[fail].next[pos] != -1)
                {
                    u = node[fail].next[pos];
                    break;
                }
                fail = node[fail].fail;
            }
            if (fail == -1)
            {
                u = 0;
            }
        }
        else
        {
            u = node[u].next[pos];
        }
        if (node[u].count != -1)
        {
            res += node[u].count;
            node[u].count = -1;
            int fail = node[u].fail;
            while (fail != -1)
            {
                if (node[fail].count == -1)
                {
                    break;
                }
                res += node[fail].count;
                node[fail].count = -1;
                fail = node[fail].fail;
            }
        }
    }
    return res;
}

void testAC(int from = ' ' - 'a', int index = 0, int space = 0)
{
    for (int i = 0; i < space; ++i)
    {
        putchar(' ');
    }
    printf("%c(%d, %d, %d)\n", from + 'a', index, node[index].count, node[index].fail);
    for (int i = 0; i < MAXC; ++i)
    {
        if (node[index].next[i] != -1)
        {
            testAC(i, node[index].next[i], space + 4);
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        initRoot();
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", word);
            insertWord(0, word);
        }
        scanf("%s", str);
        buildAC();
        printf("%d\n", searchAC(str));
    }
    return 0;
}
