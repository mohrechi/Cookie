#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int s, n;
struct Node
{
    int x, y;
    bool operator < (const Node &node) const
    {
        return x < node.x;
    }
} node[MAXN];

int main()
{
    while(~scanf("%d%d", &s, &n))
    {
        for(int i=0;i<n;++i)
        {
            scanf("%d%d", &node[i].x, &node[i].y);
        }
        sort(node, node + n);
        bool flag = true;
        for(int i=0;i<n;++i)
        {
            if(s > node[i].x)
            {
                s += node[i].y;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if(flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
