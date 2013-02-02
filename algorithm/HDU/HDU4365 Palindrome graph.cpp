#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int MOD = 100000007;

struct Node
{
    int x, y;

    Node() {}

    Node(int x0, int y0)
    {
        x = x0;
        y = y0;
    }

    bool operator < (const Node &node) const
    {
        if(x == node.x)
        {
            return y < node.y;
        }
        return x < node.x;
    }
};

int n, m, k;
set<Node> s;

int getPow(__int64 x, __int64 y)
{
    __int64 t = x;
    __int64 ans = 1;
    for(int i=0;(1<<i)<=y;++i)
    {
        if(y & (1 << i))
        {
            ans = (ans * t) % MOD;
        }
        t = (t * t) % MOD;
    }
    return (int)ans;
}

int main()
{
    int x, y, t;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int total = ((((n+1)>>1)+1)*((n+1)>>1))>>1;
        s.clear();
        while(m--)
        {
            scanf("%d%d", &x, &y);
            if(x >= (n>>1))
            {
                x = n - x - 1;
            }
            if(y >= (n>>1))
            {
                y = n - y - 1;
            }
            if(s.find(Node(x, y)) == s.end())
            {
                s.insert(Node(x, y));
                s.insert(Node(y, x));
                -- total;
            }
        }
        printf("%d\n", getPow(k, total));
    }
    return 0;
}
