#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAXN = 40001;

vector<char> pn[MAXN];

int main()
{
    int t = 0, x, y;
    while (~scanf("%d%d", &x, &y))
    {
        for (int i = 0; i <= x; ++i)
        {
            pn[i].clear();
            for (int j = 0; j <= y; ++j)
            {
                pn[i].push_back('P');
            }
        }
        for (int i = 1; i <= x; ++i)
        {
            for (int j = 1; j <= y; ++j)
            {
                if (pn[i][j] == 'P')
                {
                    for (int k = 1; i + k * j <= x; ++k)
                    {
                        pn[i + k * j][j] = 'H';
                    }
                    for (int k = 1; j + k * i <= y; ++k)
                    {
                        pn[i][j + k * i] = 'H';
                    }
                }
            }
        }
        printf("Case #%d:\n", ++t);
        for (int i = 1; i <= x; ++i)
        {
            for (int j = 1; j <= y; ++j)
            {
                putchar(pn[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
