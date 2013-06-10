#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 505;
const int MAXC = 128;
const int MAXL = 205;
const int MAXM = 10005;

int n, m;
char word[MAXL];
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
    node[nodeNum].id = 0;
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
    return ch;
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

bool visit[MAXN];
int ans[MAXN], ansNum;

void searchAC(const char *str)
{
    int u = 0;
    memset(visit, false, sizeof(visit));
    ansNum = 0;
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
        if (node[u].id && !visit[node[u].id])
        {
            visit[node[u].id] = true;
            ans[ansNum++] = node[u].id;
        }
        int fail = node[u].fail;
        while (fail != -1)
        {
            if (node[fail].id)
            {
                if (visit[node[fail].id])
                {
                    break;
                }
                else
                {
                    visit[node[fail].id] = true;
                    ans[ansNum++] = node[fail].id;
                }
            }
            fail = node[fail].fail;
        }
    }
}

void testAC(int from = ' ', int index = 0, int space = 0)
{
    for (int i = 0; i < space; ++i)
    {
        putchar(' ');
    }
    printf("%c(%d, %d, %d)\n", from, index, node[index].id, node[index].fail);
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
            gets(word);
            insertWord(0, word, i + 1);
        }
        buildAC();
        scanf("%d\n", &m);
        int total = 0;
        for (int i = 0; i < m; ++i)
        {
            gets(str);
            searchAC(str);
            if (ansNum > 0)
            {
                ++total;
                sort(ans, ans + ansNum);
                printf("web %d:", i + 1);
                for (int j = 0; j < ansNum; ++j)
                {
                    printf(" %d", ans[j]);
                }
                printf("\n");
            }
        }
        printf("total: %d\n", total);
    }
    return 0;
}
