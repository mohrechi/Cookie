#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int MAXC = 26;
const int MAXL = 55;
const int MAXM = 2000005;

int n;
char word[MAXN][MAXL];
char str[MAXM];

struct Node
{
    int next[MAXC];
    int id;
    int fail;
} node[MAXN * MAXL];
int nodeNum;

int newNode()
{
    node[nodeNum].id = -1;
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
    return ch - 'A';
}

void insertWord(int index, const char *word, int id)
{
    if (*word == 0)
    {
        node[index].id = id;
        return;
    }
    int pos = getPos(*word);
    int next = node[index].next[pos];
    if (next == -1)
    {
        next = newNode();
        node[index].next[pos] = next;
    }
    insertWord(next, word + 1, id);
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

int ans[MAXN];

void searchAC(const char *str)
{
    int u = 0;
    memset(ans, 0, sizeof(ans));
    for (int i = 0; str[i]; ++i)
    {
        if (str[i] < 'A' || str[i] > 'Z')
        {
            u = 0;
            continue;
        }
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
        if (node[u].id != -1)
        {
            ++ans[node[u].id];
        }
        int fail = node[u].fail;
        while (fail != -1)
        {
            if (node[fail].id != -1)
            {
                ++ans[node[fail].id];
            }
            fail = node[fail].fail;
        }
    }
}

void testAC(int from = ' ' - 'A', int index = 0, int space = 0)
{
    for (int i = 0; i < space; ++i)
    {
        putchar(' ');
    }
    printf("%c(%d, %d, %d)\n", from + 'A', index, node[index].id, node[index].fail);
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
    while (~scanf("%d\n", &n))
    {
        initRoot();
        for (int i = 0; i < n; ++i)
        {
            gets(word[i]);
            insertWord(0, word[i], i);
        }
        buildAC();
        int total = 0;
        gets(str);
        searchAC(str);
        for (int i = 0; i < n; ++i)
        {
            if (ans[i] > 0)
            {
                printf("%s: %d\n", word[i], ans[i]);
            }
        }
    }
    return 0;
}
