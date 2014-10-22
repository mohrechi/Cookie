#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 90000 + 10;

struct Node
{
    Node *prev, *next[26];
    int step, cnt;
    int num, child[26];
} node[MAXN * 2], *top[MAXN * 2], *head, *tail;
int nodeNum, c[MAXN * 2];

inline void insert(const int x)
{
    Node *newNode = &node[nodeNum++];
    memset(newNode->next, 0, sizeof(newNode->next));
    newNode->step = tail->step + 1;
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
    Node *p = head;
    for (int i = nodeNum - 1; i >= 0; --i)
    {
        p = top[i];
        p->num = 0;
        for (int j = 0; j < 26; ++j)
        {
            if (p->next[j])
            {
                p->cnt += p->next[j]->cnt + 1;
                p->child[p->num++] = j;
            }
        }
    }
}

void solve(int k)
{
    Node *p = head;
    while (k)
    {
        for (int i = 0; i < p->num; ++i)
        {
            int x = p->child[i];
            if (p->next[x]->cnt + 1 >= k)
            {
                putchar(x + 'a');
                p = p->next[x];
                --k;
                break;
            }
            else
            {
                k -= p->next[x]->cnt + 1;
            }
        }
    }
    putchar('\n');
}

int n, k;
char s[MAXN];

int main()
{
    scanf("%s", s);
    build(s);
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &k);
        solve(k);
    }
    return 0;
}
