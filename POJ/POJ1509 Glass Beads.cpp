#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10000 + 10;

struct Node
{
    Node *prev, *next[26];
    int step, pos;
} node[MAXN * 4], *head, *tail;
int nodeNum;

inline Node* initNode(const int step)
{
    memset(node[nodeNum].next, 0, sizeof(node[nodeNum].next));
    node[nodeNum].step = step;
    return &node[nodeNum++];
}

void init()
{
    nodeNum = 0;
    head = tail = initNode(0);
}

inline void addNode(int x, int pos)
{
    Node *newNode = initNode(tail->step + 1);
    newNode->pos = pos;
    Node *a = tail;
    while (a && 0 == a->next[x])
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
            Node *relay = initNode(a->step + 1);
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

int find(int len)
{
    Node *p = head;
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j < 26; ++j)
        {
            if (p->next[j])
            {
                p = p->next[j];
                break;
            }
        }
    }
    return p->pos - len + 1;
}

int n, l;
char s[MAXN];

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", s);
        l = strlen(s);
        init();
        for (int i = 0; i < l; ++i)
        {
            addNode(s[i] - 'a', i + 1);
        }
        for (int i = 0; i < l; ++i)
        {
            addNode(s[i] - 'a', l + i + 1);
        }
        printf("%d\n", find(l));
    }
    return 0;
}
