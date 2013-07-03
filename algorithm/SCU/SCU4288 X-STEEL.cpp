#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXP = 105;
const int MAXS = 505;

int p, s;
int w[MAXP];
int c[MAXS][MAXP];
int time[MAXP];

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &p, &s);
        for (int i = 0; i < p; ++i)
        {
            scanf("%d", &w[i]);
            time[i] = 0.0;
        }
        for (int i = 0; i < s; ++i)
        {
            for (int j = 0; j < p; ++j)
            {
                scanf("%d", &c[i][j]);
                if (c[i][j] < w[j])
                {
                    w[j] -= c[i][j];
                    ++time[j];
                }
                else if (w[j])
                {
                    w[j] = 0;
                    ++time[j];
                }
            }
        }
        int ans = -1;
        int minTime = 0x3f3f3f3f;
        for (int i = 0; i < p; ++i)
        {
            if (w[i] == 0 && time[i] < minTime)
            {
                minTime = time[i];
                ans = i;
            }
        }
        if (ans == -1)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%d\n", ans + 1);
        }
    }
    return 0;
}
