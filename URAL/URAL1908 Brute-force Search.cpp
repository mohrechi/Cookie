#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 100;

struct TreeNode
{
    int next[26];
} node[MAXN];
int nodeNum;

int initNode()
{
    memset(node[nodeNum].next, -1, sizeof(node[nodeNum].next));
    return nodeNum++;
}

void initTrie()
{
    nodeNum = 0;
    initNode();
}

void insertTrie(int index, const char* word)
{
    if (*word == 0)
    {
        return;
    }
    int next = *word - 'a';
    if (node[index].next[next] == -1)
    {
        node[index].next[next] = initNode();
    }
    insertTrie(node[index].next[next], word + 1);
}

char branch[MAXN];
int num[MAXN], choice[MAXN], skip[MAXN];

void treeDfs(int u)
{
    int choices = 0;
    num[u] = 0;
    for (int i = 0; i < 26; ++i)
    {
        int v = node[u].next[i];
        if (v != -1)
        {
            treeDfs(v);
            num[u] += num[v];
            choices += choice[v] + num[v];
        }
    }
    if (num[u] == 0)
    {
        num[u] = 1;
        choice[u] = 0;
        skip[u] = 0;
    }
    else
    {
        choice[u] = 0x7fffffff;
        skip[u] = 0x7fffffff;
        for (int i = 0; i < 26; ++i)
        {
            int v = node[u].next[i];
            if (v != -1)
            {
                choice[u] = min(choice[u], skip[v] - choice[v]);
                skip[u] = min(skip[u], skip[v] - choice[v] - num[v]);
            }
        }
        choice[u] += choices;
        skip[u] += choices;
    }
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        initTrie();
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", branch);
            insertTrie(0, branch);
        }
        treeDfs(0);
        printf("%d\n", choice[0]);
    }
    return 0;
}
