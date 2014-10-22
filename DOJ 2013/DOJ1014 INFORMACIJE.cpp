#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 205;

int n, m;

int lower[MAXN];
int upper[MAXN];
int left[MAXN];
int righ[MAXN];

bool visit[MAXN];
int link[MAXN];

bool find(int u)
{
    for (int i = left[u]; i <= righ[u]; ++i)
    {
        if (u >= lower[i] && u <= upper[i])
        {
            if (!visit[i])
            {
                visit[i] = true;
                if (link[i] == -1 || find(link[i]))
                {
                    link[i] = u;
                    return true;
                }
            }
        }
    }
    return false;
}

int hungray()
{
    int ans = 0;
    memset(link, -1, sizeof(link));
    for (int i = 1; i <= n; ++i)
    {
        memset(visit, false, sizeof(visit));
        if (find(i))
        {
            ++ans;
        }
    }
    return ans;
}

int main()
{
    int op, x, y, v;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)
        {
            lower[i] = left[i] = 1;
            upper[i] = righ[i] = n;
        }
        while (m--)
        {
            scanf("%d%d%d%d", &op, &x, &y, &v);
            left[v] = max(left[v], x);
            righ[v] = min(righ[v], y);
            for (int i = x; i <= y; ++i)
            {
                if (op == 1)
                {
                    upper[i] = min(upper[i], v);
                }
                else
                {
                    lower[i] = max(lower[i], v);
                }
            }
        }
        if (hungray() == n)
        {
            for (int i = 1; i <= n; ++i)
            {
                if (i > 1)
                {
                    printf(" ");
                }
                printf("%d", link[i]);
            }
            printf("\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
