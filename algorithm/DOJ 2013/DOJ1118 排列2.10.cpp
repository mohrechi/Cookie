#include <cstdio>
#include <cstring>

int a[100];
bool visit[100];

void judge()
{
    int x = a[0] * 100 + a[1] * 10 + a[2];
    int y = a[3] * 100 + a[4] * 10 + a[5];
    int z = a[6] * 100 + a[7] * 10 + a[8];
    if (y % x == 0 && z % x == 0 && y / x == 2 && z / x == 3)
    {
        printf("%d %d %d\n", x, y, z);
    }
}

void dfs(int depth)
{
    if (depth == 9)
    {
        judge();
        return;
    }
    for (int i = 1; i <= 9; ++i)
    {
        if (!visit[i])
        {
            visit[i] = true;
            a[depth] = i;
            dfs(depth + 1);
            visit[i] = false;
        }
    }
}

int main()
{
    memset(visit, false, sizeof(visit));
    dfs(0);
    return 0;
}
