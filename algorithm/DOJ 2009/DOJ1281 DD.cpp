#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 10005;

struct Node
{
    int a, b;
    void input()
    {
        scanf("%d%d", &a, &b);
        ++ b;
    }
    bool operator < (const Node &other) const
    {
        if(a == other.a)
        {
            return b < other.b;
        }
        return a < other.a;
    }
}node[MAXN];
int n;

int main()
{
    int t, r;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &r, &n);
        for(int i=0;i<n;++i)
        {
            node[i].input();
        }
        sort(node, node + n);
        int l = node[0].a, r = node[0].b;
        int ans = 0;
        for(int i=1;i<n;++i)
        {
            if(node[i].a <= r)
            {
                r = max(node[i].b, r);
            }
            else
            {
                ans += r - l;
                l = node[i].a;
                r = node[i].b;
            }
        }
        ans += r - l;
        printf("%d\n", ans);
    }
    return 0;
}
