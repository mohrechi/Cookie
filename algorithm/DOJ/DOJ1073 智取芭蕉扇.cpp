#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Node
{
    int index;
    int value;
    bool operator < (const Node &node) const
    {
        return value > node.value;
    }
} node[65536];

int main()
{
    int n, a;
    while(scanf("%d", &n), n)
    {
        for(int i=0;i<65536;++i)
        {
            node[i].index = i;
            node[i].value = 0;
        }
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a);
            ++ node[a].value;
        }
        sort(node, node + 65536);
        printf("%d\n", node[0].index);
    }
    return 0;
}
