#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

bool a[MAXN][MAXN];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        if (n == 4)
        {
            printf("-1\n");
            continue;
        }
        memset(a, false, sizeof(a));
        for (int i = 0; i < n; ++i)
        {
            a[i][(i + 1) % n] = true;
            for (int j = i + 2; j < n; ++j)
            {
                if ((j - i) & 1)
                {
                    a[j][i] = true;
                }
                else
                {
                    a[i][j] = true;
                }
            }
        }
        a[0][n - 1] = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                printf("%d ", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
