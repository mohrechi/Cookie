#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50;

int n, init[MAXN], target[MAXN];
bool mat[MAXN][MAXN];

int gauss()
{
    int i = 0;
    for (int j = 0; j < n; ++j)
    {
        for (int k = i; k < n; ++k)
        {
            if (mat[k][j])
            {
                if (k != i)
                {
                    for (int l = j; l <= n; ++l)
                    {
                        swap(mat[i][l], mat[k][l]);
                    }
                }
                break;
            }
        }
        if (mat[i][j])
        {
            for (int k = i + 1; k < n; ++k)
            {
                if (mat[k][j])
                {
                    for (int l = n; l >= j; --l)
                    {
                        mat[k][l] ^= mat[i][l];
                    }
                }
            }
            ++i;
        }
    }
    for (int j = i; j < n; ++j)
    {
        if (mat[j][n])
        {
            return 0;
        }
    }
    return 1 << (n - i);
}

int main()
{
    int k, x, y;
    scanf("%d", &k);
    while (k--)
    {
        scanf("%d", &n);
        memset(mat, false, sizeof(mat));
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &init[i]);
        }
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &target[i]);
            mat[i][i] = true;
            if (init[i] != target[i])
            {
                mat[i][n] = true;
            }
        }
        while (scanf("%d%d", &x, &y), x || y)
        {
            mat[y - 1][x - 1] = true;
        }
        int ans = gauss();
        if (ans)
        {
            printf("%d\n", ans);
        }
        else
        {
            puts("Oh,it's impossible~!!");
        }
    }
    return 0;
}
