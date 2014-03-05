#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 250000 + 10;

struct Node
{
    Node *prev, *next[26];
    int step, cnt;
} node[MAXN * 2], *top[MAXN * 2], *head, *tail;
int nodeNum, c[MAXN * 2];

inline void insert(const int x)
{
    Node *newNode = &node[nodeNum++];
    memset(newNode->next, 0, sizeof(newNode->next));
    newNode->step = tail->step + 1;
    newNode->cnt = 0;
    Node *a = tail;
    while (a && !a->next[x])
    {
        a->next[x] = newNode;
        a = a->prev;
    }
    if (a)
    {
        Node *b = a->next[x];
        if (a->step + 1 == b->step)
        {
            newNode->prev = b;
        }
        else
        {
            Node *relay = &node[nodeNum++];
            *relay = *b;
            relay->step = a->step + 1;
            b->prev = newNode->prev = relay;
            while (a && a->next[x] == b)
            {
                a->next[x] = relay;
                a = a->prev;
            }
        }
    }
    else
    {
        newNode->prev = head;
    }
    tail = newNode;
}

void getTop(int len)
{
    memset(c, 0, sizeof(c));
    for (int i = 0; i < nodeNum; ++i)
    {
        ++c[node[i].step];
    }
    for (int i = 1; i <= len; ++i)
    {
        c[i] += c[i - 1];
    }
    for (int i = 0; i < nodeNum; ++i)
    {
        top[--c[node[i].step]] = &node[i];
    }
}

void build(const char *s)
{
    int len;
    nodeNum = 0;
    head = tail = &node[nodeNum++];
    for (len = 0; s[len]; ++len)
    {
        insert(s[len] - 'a');
    }
    getTop(len);
}

int ans[MAXN];
char s[MAXN];

void solve(const char *s)
{
    int len;
    build(s);
    Node *p = head;
    for (len = 0; s[len]; ++len)
    {
        p = p->next[s[len] - 'a'];
        ++p->cnt;
    }
    memset(ans, 0, sizeof(ans));
    for (int i = nodeNum - 1; i > 0; --i)
    {
        p = top[i];
        ans[p->step] = max(ans[p->step], p->cnt);
        p->prev->cnt += p->cnt;
    }
    for (int i = len - 1; i >= 1; --i)
    {
        ans[i] = max(ans[i], ans[i + 1]);
    }
}

int main()
{
    while (gets(s))
    {
        solve(s);
        for (int i = 0; s[i]; ++i)
        {
            printf("%d\n", ans[i + 1]);
        }
    }
    return 0;
}
