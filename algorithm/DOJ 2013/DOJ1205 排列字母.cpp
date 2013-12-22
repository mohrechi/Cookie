#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXS = 100 + 5;

int n, k;
char s[MAXS];
char last[MAXS];
char temp[MAXS];
int num[26];

struct Node
{
    int order, index;
    bool operator <(const Node &node) const
    {
        if (order == node.order)
        {
            return index < node.index;
        }
        return order < node.order;
    }
} node[26];

void dfs(int depth)
{
    if (k == 0)
    {
        return;
    }
    if (depth == n)
    {
        temp[n] = 0;
        if (strcmp(temp, last))
        {
            strcpy(last, temp);
            puts(temp);
            --k;
        }
        return;
    }
    for (int i = 0; i < 26 && k; ++i)
    {
        if (num[node[i].index])
        {
            temp[depth] = node[i].index + 'A';
            --num[node[i].index];
            dfs(depth + 1);
            ++num[node[i].index];
        }
    }
}

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%s", s);
        n = strlen(s);
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; ++i)
        {
            ++num[s[i] - 'A'];
        }
        for (int i = 0; i < 26; ++i)
        {
            node[i].index = i;
            scanf("%d", &node[i].order);
        }
        sort(node, node + 26);
        scanf("%d", &k);
        last[0] = 0;
        dfs(0);
    }
    return 0;
}
