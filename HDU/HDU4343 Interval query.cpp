#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100010;

struct Node
{
    int a, b;

    inline void input()
    {
        scanf("%d%d", &a, &b);
    }

    inline void output() const
    {
        printf("%d %d\n", a, b);
    }

    bool operator < (const Node &node) const
    {
        if(a == node.a)
        {
            return b > node.b;
        }
        return a < node.a;
    }
}node[MAXN];
int n, m;

void decrease()
{
    int k = 0;
    for(int i=0;i<n;++i)
    {
        bool flag = true;
        for(int j=i+1;j<n;++j)
        {
            if(node[j].a >= node[i].a && node[j].b <= node[i].b)
            {
                flag = false;
                break;
            }
            if(node[j].a >= node[i].b)
            {
                break;
            }
        }
        if(flag)
        {
            node[k++] = node[i];
        }
    }
    n = k;
}

int main()
{
    int a, b;
    while(~scanf("%d%d", &n, &m))
    {
        for(int i=0;i<n;++i)
        {
            node[i].input();
        }
        sort(node, node + n);
        decrease();
        while(m--)
        {
            scanf("%d%d", &a, &b);
            int i;
            for(i=0;i<n;++i)
            {
                if(node[i].a >= a)
                {
                    break;
                }
            }
            int cnt = 0;
            int right = a;
            for(;i<n;++i)
            {
                if(node[i].a >= right && node[i].b <= b)
                {
                    ++ cnt;
                    right = node[i].b;
                }
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}
