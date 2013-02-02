#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 101;

struct Nodes
{
    struct Node
    {
        char s[25];
        inline void input()
        {
            scanf("%s", s);
        }
        bool operator < (const Node &node) const
        {
            return strcmp(s, node.s) < 0;
        }
    } node[MAXN];
    int num;
    inline void clear()
    {
        num = 0;
    }
    inline void input(int n)
    {
        for(int i=0;i<n;++i)
        {
            node[i].input();
        }
        num = n;
    }
    inline void sortNode()
    {
        sort(node, node + num);
    }
    inline int find(const char *s)
    {
        int l = 0, r = num - 1;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            int res = strcmp(node[mid].s, s);
            if(res == 0)
            {
                return mid;
            }
            else if(res > 0)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return -1;
    }
}a, b, c;

char s1[25], s2[25];
bool map[3][MAXN][MAXN];

int main()
{
    int t, n, m, k, r;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        a.input(n);
        a.sortNode();
        b.input(m);
        b.sortNode();
        c.input(k);
        c.sortNode();
        memset(map, true, sizeof(map));
        scanf("%d", &r);
        while(r--)
        {
            scanf("%s%s", s1, s2);
            int a1 = a.find(s1), a2 = a.find(s2);
            int b1 = b.find(s1), b2 = b.find(s2);
            int c1 = c.find(s1), c2 = c.find(s2);
            if(a1 == -1 && a2 == -1)
            {
                if(b1 == -1)
                {
                    map[1][b2][c1] = false;
                }
                else
                {
                    map[1][b1][c2] = false;
                }
            }
            else if(b1 == -1 && b2 == -1)
            {
                if(a1 == -1)
                {
                    map[2][c1][a2] = false;
                }
                else
                {
                    map[2][c2][a1] = false;
                }
            }
            else
            {
                if(a1 == -1)
                {
                    map[0][a2][b1] = false;
                }
                else
                {
                    map[0][a1][b2] = false;
                }
            }
        }
        int count = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                for(int l=0;l<k;++l)
                {
                    if(map[0][i][j] && map[1][j][l] && map[2][l][i])
                    {
                        ++ count;
                    }
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
