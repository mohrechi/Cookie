#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int DIR_X[] = {1, 0, -1, 0};
const int DIR_Y[] = {0, 1, 0, -1};

int n, m;
int sx, sy;
int ex, ey;
char map[MAXN][MAXN];
int step[MAXN][MAXN];
int qx[MAXN * MAXN];
int qy[MAXN * MAXN];

void bfs()
{
    int front = 0, rear = 1;
    memset(step, -1, sizeof(step));
    qx[0] = sx;
    qy[0] = sy;
    step[sx][sy] = 0;
    while (front < rear)
    {
        int x = qx[front];
        int y = qy[front];
        for (int i = 0; i < 4; ++i)
        {
            int tx = x + DIR_X[i];
            int ty = y + DIR_Y[i];
            if (tx >= 0 && tx < n)
            {
                if (ty >= 0 && ty < m)
                {
                    if (map[tx][ty] != 'T')
                    {
                        if (step[tx][ty] == -1)
                        {
                            step[tx][ty] = step[x][y] + 1;
                            qx[rear] = tx;
                            qy[rear] = ty;
                            ++rear;
                        }
                    }
                }
            }
        }
        ++front;
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; ++i)
        {
            scanf("%s", map[i]);
            for (int j = 0; j < m; ++j)
            {
                if (map[i][j] == 'E')
                {
                    sx = i;
                    sy = j;
                }
                else if (map[i][j] == 'S')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        bfs();
        int stepNum = step[ex][ey];
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (map[i][j] >= '1' && map[i][j] <= '9')
                {
                    if (step[i][j] != -1 && step[i][j] <= stepNum)
                    {
                        ans += map[i][j] - '0';
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
