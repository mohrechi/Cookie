#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;
const int DIRX[] = {0, 1, 0, -1};
const int DIRY[] = {1, 0, -1, 0};

int n, m;
char map[MAXN][MAXN];
int step[MAXN][MAXN];
int qx[MAXN * MAXN], qy[MAXN * MAXN];
int front, rear;

int main()
{
    int q, x, y;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        m = 0;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%s", map[i] + 1);
            for (int j = 1; j <= n; ++j)
            {
                m += map[i][j] == '#';
            }
        }
        scanf("%d%d", &x, &y);
        memset(step, -1, sizeof(step));
        front = 0, rear = 0;
        int ans = -1;
        int cnt = 0;
        if (map[x][y] == '#')
        {
            step[x][y] = 0;
            qx[rear] = x;
            qy[rear] = y;
            ++rear;
            ++cnt;
        }
        for (int i = 0; i < 4; ++i)
        {
            int tx = x + DIRX[i];
            int ty = y + DIRY[i];
            if (tx >= 1 && tx <= n)
            {
                if (ty >= 1 && ty <= n)
                {
                    if (map[tx][ty] == '#')
                    {
                        step[tx][ty] = 0;
                        qx[rear] = tx;
                        qy[rear] = ty;
                        ++rear;
                        ++cnt;
                    }
                }
            }
        }
        if (cnt > m >> 1)
        {
            ans = 0;
            front = rear;
        }
        while (front < rear)
        {
            x = qx[front];
            y = qy[front];
            for (int i = 0; i < 4; ++i)
            {
                int tx = x + DIRX[i];
                int ty = y + DIRY[i];
                if (tx >= 1 && tx <= n)
                {
                    if (ty >= 1 && ty <= n)
                    {
                        if (map[tx][ty] == '#' && step[tx][ty] == -1)
                        {
                            step[tx][ty] = step[x][y] + 1;
                            qx[rear] = tx;
                            qy[rear] = ty;
                            ++rear;
                            if (++cnt > m >> 1)
                            {
                                ans = step[tx][ty];
                                front = rear;
                                break;
                            }
                        }
                    }
                }
            }
            ++front;
        }
        printf("%d\n", ans);
    }
    return 0;
}
