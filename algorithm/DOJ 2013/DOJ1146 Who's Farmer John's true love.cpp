#include <cstdio>
const int MAXN = 1e5 + 5;
const int MAXM = 30 + 5;

struct Node
{
    char name[MAXM];
    int x, y;
    long long dist;
    void input()
    {
        scanf("%s%d%d", name, &x, &y);
        dist = 1LL * x * x + 1LL * y * y;
    }
} node[MAXN];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        long long dist = 0x7fffffffffffffffLL;
        for (int i = 0; i < n; ++i)
        {
            node[i].input();
            if (node[i].dist < dist)
            {
                dist = node[i].dist;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (node[i].dist == dist)
            {
                puts(node[i].name);
            }
        }
        putchar('\n');
    }
    return 0;
}
