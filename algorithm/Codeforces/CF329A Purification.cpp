#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;

int n;
char map[MAXN][MAXN];
int sumH[MAXN], sumV[MAXN];

int main()
{
    while (~scanf("%d", &n))
    {
        memset(sumH, 0, sizeof(sumH));
        memset(sumV, 0, sizeof(sumV));
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", map[i] + 1);
            for (int j = 1; j <= n; ++j)
            {
                sumH[i] += map[i][j] == '.';
                sumV[j] += map[i][j] == '.';
            }
        }
        bool noneH = false;
        bool noneV = false;
        for (int i = 1; i <= n; ++i)
        {
            if (sumH[i] == 0)
            {
                noneH = true;
            }
            if (sumV[i] == 0)
            {
                noneV = true;
            }
        }
        if (noneH && noneV)
        {
            printf("-1\n");
        }
        else
        {
            if (noneH)
            {
                for (int j = 1; j <= n; ++j)
                {
                    for (int i = 1; i <= n; ++i)
                    {
                        if (map[i][j] == '.')
                        {
                            printf("%d %d\n", i, j);
                            break;
                        }
                    }
                }
            }
            else
            {
                for (int i = 1; i <= n; ++i)
                {
                    for (int j = 1; j <= n; ++j)
                    {
                        if (map[i][j] == '.')
                        {
                            printf("%d %d\n", i, j);
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
