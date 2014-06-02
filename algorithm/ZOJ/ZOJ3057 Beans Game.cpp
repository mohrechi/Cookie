#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 300 + 1;

bool pn[MAXN][MAXN][MAXN];

int main()
{
    int a, b, c;
    for (int i = 0; i < MAXN; ++i)
    {
        for (int j = 0; j < MAXN; ++j)
        {
            for (int k = 0; k < MAXN; ++k)
            {
                if (!pn[i][j][k])
                {
                    for (int l = 1; l < MAXN; ++l)
                    {
                        if (i + l < MAXN)
                        {
                            pn[i + l][j][k] = 1;
                        }
                        if (j + l < MAXN)
                        {
                            pn[i][j + l][k] = 1;
                        }
                        if (k + l < MAXN)
                        {
                            pn[i][j][k + l] = 1;
                        }
                        if (i + l < MAXN && j + l < MAXN)
                        {
                            pn[i + l][j + l][k] = 1;
                        }
                        if (i + l < MAXN && k + l < MAXN)
                        {
                            pn[i + l][j][k + l] = 1;
                        }
                        if (j + l < MAXN && k + l < MAXN)
                        {
                            pn[i][j + l][k + l] = 1;
                        }
                    }
                }
            }
        }
    }
    while (~scanf("%d%d%d", &a, &b, &c))
    {
        printf("%d\n", pn[a][b][c]);
    }
    return 0;
}
