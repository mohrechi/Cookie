#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 250000 + 10;

struct Node
{
    Node *prev, *next[26];
    int val;
} *root, *tail, node[MAXN * 2];
int nodeNum;

inline Node* initNode()
{
    memset(node[nodeNum].next, 0, sizeof(node[nodeNum].next));
    return &node[nodeNum++];
}

inline void addNode(int c, int l)
{
    Node* newTail = initNode();
    newTail->val = l;
    Node* a = tail;
    while (a && a->next[c] == 0)
    {
        a->next[c] = newTail;
        a = a->prev;
    }
    if (0 == a)
    {
        newTail->prev = root;
    }
    else
    {
        Node* b = a->next[c];
        if (a->val + 1 == b->val)
        {
            newTail->prev = b;
        }
        else
        {
            Node *relay = initNode();
            *relay = *b;
            relay->val = a->val + 1;
            newTail->prev = b->prev = relay;
            while (a && a->next[c] == b)
            {
                a->next[c] = relay;
                a = a->prev;
            }
        }
    }
    tail = newTail;
}

void build(char *s, int n)
{
    nodeNum = 0;
    root = tail = initNode();
    root->val = 0;
    root->prev = 0;
    for (int i = 0; i < n; ++i)
    {
        addNode(s[i] - 'a', i + 1);
    }
}

char s[MAXN];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    build(s, n);
    scanf("%s", s);
    int ans = 0, cnt = 0;
    Node *p = root;
    for (int i = 0; s[i]; ++i)
    {
        int c = s[i] - 'a';
        if (p->next[c])
        {
            p = p->next[c];
            ans = max(ans, ++cnt);
        }
        else
        {
            while (p && p->next[c] == 0)
            {
                p = p->prev;
            }
            if (p)
            {
                cnt = p->val + 1;
                p = p->next[c];
            }
            else
            {
                p = root;
                cnt = 0;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
