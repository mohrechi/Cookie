#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

struct Node
{
    char s[55];
    bool visit;
    bool operator < (const Node &node) const
    {
        return strcmp(s, node.s) < 0;
    }
} node[MAXN];

int main()
{
    int n, cas = 0;
    while(scanf("%d", &n), n)
    {
        for(int i=0;i<n;++i)
        {
            scanf("%s", node[i].s);
            node[i].visit = false;
        }
        sort(node, node + n);
        for(int i=1;i<n;++i)
        {
            scanf("%s", node[n].s);
            int l = 0, r = n - 1;
            while(l <= r)
            {
                int mid = (l + r) >> 1;
                int res = strcmp(node[mid].s, node[n].s);
                if(res == 0)
                {
                    node[mid].visit = true;
                    break;
                }
                else if(res < 0)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }
            }
        }
        printf("Case %d :", ++ cas);
        for(int i=0;i<n;++i)
        {
            if(!node[i].visit)
            {
                printf("%s\n", node[i].s);
                break;
            }
        }
        printf("\n");
    }
    return 0;
}
