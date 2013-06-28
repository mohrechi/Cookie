#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 65;
const int DIR_X[] = {0, 1, 0, -1};
const int DIR_Y[] = {1, 0, -1, 0};

int num[2][MAXN][MAXN];
int edge = 0;

void dfs(int curr)
{
    int prev = 1 - curr;
    bool flag = false;
    memset(num[curr], 0, sizeof(num[curr]));
    for (int i = 0; i <= edge; ++i)
    {
        for (int j = i; j <= edge; ++j)
        {
            if (num[prev][i][j] >= 4)
            {
                flag = true;
                for (int k = 0; k < 4; ++k)
                {
                    int ti = i + DIR_X[k];
                    int tj = j + DIR_Y[k];
                    if (ti < 0 || tj < 0)
                    {
                        continue;
                    }
                    if (ti == 0 && tj == 0)
                    {
                        num[curr][ti][tj] += (num[prev][i][j] >> 2) << 2;
                    }
                    else if (ti == 0)
                    {
                        if (k == 0 || k == 2)
                        {
                            num[curr][ti][tj] += num[prev][i][j] >> 2;
                        }
                        else
                        {
                            num[curr][ti][tj] += (num[prev][i][j] >> 2) << 1;
                        }
                    }
                    else if (ti == tj)
                    {
                        num[curr][ti][tj] += (num[prev][i][j] >> 2) << 1;
                    }
                    else
                    {
                        num[curr][ti][tj] += num[prev][i][j] >> 2;
                    }
                }
                edge = max(edge, j + 1);
            }
            num[curr][i][j] += num[prev][i][j] & 3;
        }
    }
    if (flag)
    {
        dfs(1 - curr);
    }
    else
    {
        memcpy(num[prev], num[curr], sizeof(num[curr]));
    }
}

int main()
{
    int n, t, x, y;
    scanf("%d%d", &n, &t);
    num[0][0][0] = n;
    dfs(1);
    while (t--)
    {
        scanf("%d%d", &x, &y);
        x = abs(x);
        y = abs(y);
        if (x > y)
        {
            swap(x, y);
        }
        if (x < MAXN && y < MAXN)
        {
            printf("%d\n", num[0][x][y]);
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
