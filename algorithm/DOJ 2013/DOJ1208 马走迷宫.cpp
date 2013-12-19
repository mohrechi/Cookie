#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;
const int BLOCKX[8] = {-1, -1, 1, 1, 0, 0, 0, 0};
const int BLOCKY[8] = {0, 0, 0, 0, -1, -1, 1, 1};
const int STEPX[8] = {-2, -2, 2, 2, -1, 1, -1, 1};
const int STEPY[8] = {-1, 1, -1, 1, -2, -2, 2, 2};

int n, step[MAXN][MAXN];
char map[MAXN][MAXN];
int sx, sy, ex, ey;
bool visit[MAXN][MAXN];
int qx[MAXN * MAXN], qy[MAXN * MAXN];

inline bool valid(int x, int y)
{
    return map[x][y] != '#' && x >= 1 && x <= n && y >= 1 && y <= n;
}

int main()
{
    int q;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", map[i] + 1);
            for (int j = 1; j <= n; ++j)
            {
                if (map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                else if (map[i][j] == 'E')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        memset(step, -1, sizeof(step));
        memset(visit, false, sizeof(visit));
        step[sx][sy] = 0;
        visit[sx][sy] = true;
        int front = 0, rear = 1;
        qx[0] = sx;
        qy[0] = sy;
        while (front != rear)
        {
            int x = qx[front];
            int y = qy[front];
            for (int k = 0; k < 8; ++k)
            {
                int tx = x + STEPX[k];
                int ty = y + STEPY[k];
                if (valid(x + BLOCKX[k], y + BLOCKY[k]) && valid(tx, ty))
                {
                    if (step[tx][ty] > step[x][y] + 1 || step[tx][ty] == -1)
                    {
                        step[tx][ty] = step[x][y] + 1;
                        if (!visit[tx][ty])
                        {
                            visit[tx][ty] = true;
                            qx[rear] = tx;
                            qy[rear] = ty;
                            if (++rear >= MAXN * MAXN)
                            {
                                rear = 0;
                            }
                        }
                    }
                }
            }
            visit[x][y] = false;
            if (++front >= MAXN * MAXN)
            {
                front = 0;
            }
        }
        printf("%d\n", step[ex][ey]);
    }
    return 0;
}
