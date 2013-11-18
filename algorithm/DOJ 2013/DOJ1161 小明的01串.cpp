#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int MAXL = 260;

struct Node
{
    int len;
    int num;
    char s[MAXL];
    inline void input()
    {
        scanf("%s", s);
        len = strlen(s);
        num = 0;
        for (int i = 0; i < len; ++i)
        {
            num += s[i] == '1';
        }
    }
    inline void output()
    {
        puts(s);
    }
    bool operator <(const Node &node) const
    {
        if (len == node.len)
        {
            if (num == node.num)
            {
                return strcmp(s, node.s) < 0;
            }
            return num > node.num;
        }
        return len > node.len;
    }
} node[MAXN];

int main()
{
    int T, n;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            node[i].input();
        }
        sort(node, node + n);
        for (int i = 0; i < n; ++i)
        {
            node[i].output();
        }
        if (T)
        {
            putchar('\n');
        }
    }
    return 0;
}
