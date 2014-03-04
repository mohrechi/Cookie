#include <cstdio>
const int MAXN = 100000 + 10;
const int INF = MAXN * 10;

struct Node
{
    Node *prev, *next[26];
    int step, high, low;
} node[MAXN * 2], *top[MAXN * 2], *head, *tail;
int nodeNum, c[MAXN * 2];

inline Node* initNode()
{
    node[nodeNum].low = INF;
    return &node[nodeNum++];
}

inline void addNode(const int x)
{
    Node *newNode = initNode();
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
            Node *relay = initNode();
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
    int l;
    nodeNum = 0;
    head = tail = initNode();
    for (l = 0; s[l]; ++l)
    {
        addNode(s[l] - 'a');
    }
    getTop(l);
}

void match(const char *s)
{
    Node *p = head;
    int cnt = 0;
    for (int i = 0; s[i]; ++i)
    {
        int x = s[i] - 'a';
        if (p->next[x])
        {
            p = p->next[x];
            ++cnt;
        }
        else
        {
            while (p && !p->next[x])
            {
                p = p->prev;
            }
            if (p)
            {
                cnt = p->step + 1;
                p = p->next[x];
            }
            else
            {
                p = head;
                cnt = 0;
            }
        }
        if (cnt > p->high)
        {
            p->high = cnt;
        }
    }
    for (int i = nodeNum - 1; i >= 0; --i)
    {
        p = top[i];
        if (p->prev && p->prev->high < p->high)
        {
            p->prev->high = p->high;
            if (p->prev->high > p->prev->step)
            {
                p->prev->high = p->prev->step;
            }
        }
        if (p->high < p->low)
        {
            p->low = p->high;
        }
        p->high = 0;
    }
}

int find()
{
    int ans = 0;
    for (int i = 0; i < nodeNum; ++i)
    {
        if (node[i].low > ans)
        {
            ans = node[i].low;
        }
    }
    return ans;
}

char s[MAXN];

int main()
{
    gets(s);
    build(s);
    while (gets(s))
    {
        match(s);
    }
    printf("%d\n", find());
    return 0;
}
