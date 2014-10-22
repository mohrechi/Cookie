#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 15;
const int MAXL = 10000;
const int MAXM = MAXN * MAXL + 5;

int n;
int l[MAXN];
set<__int64> triangles[MAXN + 1];

__int64 getStatus(int a, int b, int c)
{
    return (__int64)a * MAXM * MAXM + (__int64)b * MAXM + c;
}

inline int abs(int x)
{
    return x >= 0 ? x : -x;
}

bool isTriangle(int a, int b, int c)
{
    return a + b > c && b + c > a && c + a > b &&
           abs(a - b) < c && abs(b - c) < a && abs(c - a) < b &&
           a != 0 && b != 0 && c != 0;
}

void dfs(int index, int a, int b, int c)
{
    if (a > b)
    {
        swap(a, b);
    }
    if (a > c)
    {
        swap(a, c);
    }
    if (b > c)
    {
        swap(b, c);
    }
    __int64 status = getStatus(a, b, c);
    if (triangles[index].find(status) != triangles[index].end())
    {
        return;
    }
    else
    {
        if (index == n)
        {
            if (isTriangle(a, b, c))
            {
                triangles[index].insert(status);
            }
            return;
        }
        else
        {
            triangles[index].insert(status);
        }
    }
    dfs(index + 1, a + l[index], b, c);
    dfs(index + 1, a, b + l[index], c);
    dfs(index + 1, a, b, c + l[index]);
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &l[i]);
        }
        for (int i = 0; i <= n; ++i)
        {
            triangles[i].clear();
        }
        dfs(0, 0, 0, 0);
        printf("%d\n", triangles[n].size());
    }
    return 0;
}
