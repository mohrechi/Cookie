#include <cstdio>
#include <cstring>
const int MAXN = 25;

int main()
{
    int t, n, mat[MAXN][MAXN];
    bool flag = true;
    scanf("%d", &t);
    while (t--)
    {
        if (flag)
        {
            flag = false;
        }
        else
        {
            putchar('\n');
        }
        scanf("%d", &n);
        memset(mat, -1, sizeof(mat));
        int x = n, y = 1, z = 0;
        mat[x][y] = ++z;
        while (z != n * n)
        {
            if (-1 == mat[x][y - 1])
            {
                --x;
                while (true)
                {
                    mat[x][y] = ++z;
                    if (-1 == mat[x + 1][++y])
                    {
                        break;
                    }
                }
                while (true)
                {
                    mat[x][y] = ++z;
                    if (-1 == mat[++x][y - 1])
                    {
                        break;
                    }
                }
                --x;
            }
            else
            {
                ++y;
                while (true)
                {
                    mat[x][y] = ++z;
                    if (-1 == mat[--x][y - 1])
                    {
                        break;
                    }
                }
                while (true)
                {
                    mat[x][y] = ++z;
                    if (-1 == mat[x + 1][--y])
                    {
                        break;
                    }
                }
                ++y;
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j > 1)
                {
                    putchar(' ');
                }
                printf("%d", mat[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
