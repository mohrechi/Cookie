#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;

int h, b;
char map[MAXN][MAXN];
int sum[MAXN][MAXN];
int num1[MAXN][MAXN];
int num2[MAXN][MAXN];
bool visit[MAXN][MAXN];

void printArray(int a[MAXN][MAXN])
{
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= b; ++j)
        {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void testPrint()
{
    printArray(sum);
    printArray(num1);
    printArray(num2);
}

int getNum(int sx, int sy, int ex, int ey)
{
    if (ex < sx)
    {
        swap(sx, ex);
    }
    if (ey < sy)
    {
        swap(sy, ey);
    }
    return sum[ex][ey] - sum[ex][sy - 1] - sum[sx - 1][ey] + sum[sx - 1][sy - 1];
}

bool judge(int sx, int sy, int ex, int ey, int num)
{
    return getNum(sx, sy, ex, ey) == num;
}

int main()
{
    while (~scanf("%d%d", &h, &b))
    {
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= h; ++i)
        {
            scanf("%s", map[i] + 1);
        }
        memset(sum, 0, sizeof(sum));
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= b; ++j)
            {
                if (map[i][j] == '.')
                {
                    sum[i][j] = sum[i][j - 1];
                    num1[i][j] = 0;
                    num2[i][j] = 0;
                }
                else
                {
                    sum[i][j] = sum[i][j - 1] + 1;
                    num1[i][j] = num1[i - 1][j - 1] + 1;
                    num2[i][j] = num2[i - 1][j + 1] + 1;
                }
            }
        }
        for (int j = 1; j <= b; ++j)
        {
            for (int i = 1; i <= h; ++i)
            {
                sum[i][j] += sum[i - 1][j];
            }
        }
        int ans = 0;
        memset(visit, false, sizeof(visit));
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= b; ++j)
            {
                if (map[i][j] == '*' && !visit[i][j])
                {
                    ans = max(ans, 1);
                    int sx = i;
                    int sy = j;
                    int ex = i;
                    int ey = j;
                    int len = 1;
                    visit[i][j] = true;
                    while (ex <= h && ey <= b)
                    {
                        ++ex;
                        ++ey;
                        ++len;
                        if (map[ex][ey] != '*')
                        {
                            break;
                        }
                        visit[ex][ey] = true;
                        while (!judge(sx, sy, ex, ey, len))
                        {
                            ++sx;
                            ++sy;
                            --len;
                            if (sx == ex && sy == ey)
                            {
                                break;
                            }
                        }
                        ans = max(ans, len);
                    }
                }
            }
        }

        memset(visit, false, sizeof(visit));
        for (int i = 1; i <= h; ++i)
        {
            for (int j = 1; j <= b; ++j)
            {
                if (map[i][j] == '*' && !visit[i][j])
                {
                    ans = max(ans, 1);
                    int sx = i;
                    int sy = j;
                    int ex = i;
                    int ey = j;
                    int len = 1;
                    visit[i][j] = true;
                    while (ex <= h && ey >= 1)
                    {
                        ++ex;
                        --ey;
                        ++len;
                        if (map[ex][ey] != '*')
                        {
                            break;
                        }
                        visit[ex][ey] = true;
                        while (!judge(sx, sy, ex, ey, len))
                        {
                            ++sx;
                            --sy;
                            --len;
                            if (sx == ex && sy == ey)
                            {
                                break;
                            }
                        }
                        ans = max(ans, len);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
