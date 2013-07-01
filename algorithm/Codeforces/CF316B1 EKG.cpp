#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int n, x;
int a[MAXN];
int father[MAXN];
int len[MAXN];
bool visit[MAXN];

void init()
{
    for (int i = 1; i <= n; ++i)
    {
        father[i] = i;
        len[i] = 1;
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
    father[x] = y;
    len[y] += len[x];
    len[x] = 0;
}

int main()
{
    while (~scanf("%d%d", &n, &x))
    {
        init();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            if (a[i])
            {
                if (find(i) != find(a[i]))
                {
                    combine(i, a[i]);
                }
            }
        }
        int shift = 1;
        int temp = x;
        while (a[temp])
        {
            ++shift;
            temp = a[temp];
        }
        memset(visit, false, sizeof(visit));
        visit[0] = true;
        for (int i = 1; i <= n; ++i)
        {
            if (len[i])
            {
                if (find(x) == find(i))
                {
                    continue;
                }
                for (int j = n; j >= len[i]; --j)
                {
                    if (visit[j - len[i]])
                    {
                        visit[j] = true;
                    }
                }
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (visit[i])
            {
                printf("%d\n", i + shift);
            }
        }
    }
    return 0;
}
