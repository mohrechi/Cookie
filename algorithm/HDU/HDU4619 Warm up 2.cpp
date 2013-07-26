#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

struct Node
{
    int x, y;
    Node(){}
    Node (int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    inline void input()
    {
        scanf("%d%d", &x, &y);
    }
    Node horizon()
    {
        return Node(x + 1, y);
    }
    Node vertical()
    {
        return Node(x, y + 1);
    }
} h[MAXN], v[MAXN];

bool operator ==(const Node &a ,const Node &b)
{
    return a.x == b.x && a.y == b.y;
}

int n, m;
int father[MAXN * 2];
int num[MAXN * 2];

void init()
{
    for (int i = 0; i < (n + m); ++i)
    {
        father[i] = i;
        num[i] = 1;
    }
}

int find(int x)
{
    if (x == father[x])
    {
        return x;
    }
    return father[x] = find(father[x]);
}

void combine(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        num[x] += num[y];
        num[y] = 0;
        father[y] = x;
        father[y] = x;
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m), n || m)
    {
        for (int i = 0; i < n; ++i)
        {
            h[i].input();
        }
        for (int i = 0; i < m; ++i)
        {
            v[i].input();
        }
        init();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (v[i] == h[j] ||
                    v[i] == h[j].horizon() ||
                    v[i].vertical() == h[j] ||
                    v[i].vertical() == h[j].horizon())
                {
                    combine(i + n, j);
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < (n + m); ++i)
        {
            sum += num[i] >> 1;
        }
        printf("%d\n", n + m - sum);
    }
    return 0;
}
