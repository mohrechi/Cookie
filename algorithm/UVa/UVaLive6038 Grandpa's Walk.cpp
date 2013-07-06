#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 55;
const int DIR_X[] = {0, 1, 0, -1};
const int DIR_Y[] = {1, 0, -1, 0};

//#define DEBUG

int n, m;
int a[MAXN][MAXN];

inline bool isInside(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

inline bool isMinimum(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + DIR_X[i];
        int ty = y + DIR_Y[i];
        if (isInside(tx, ty))
        {
            if (a[tx][ty] < a[x][y])
            {
                return false;
            }
        }
    }
    return true;
}

inline bool isMaximum(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int tx = x + DIR_X[i];
        int ty = y + DIR_Y[i];
        if (isInside(tx, ty))
        {
            if (a[tx][ty] > a[x][y])
            {
                return false;
            }
        }
    }
    return true;
}

int qx[MAXN * MAXN];
int qy[MAXN * MAXN];
long long way[MAXN][MAXN];
bool visit[MAXN][MAXN];

void bfs(int x, int y)
{
    int front = 0, rear = 1;
    memset(visit, false, sizeof(visit));
    visit[x][y] = true;
    way[x][y] = 1;
    qx[0] = x;
    qy[0] = y;
    while (front != rear)
    {
        x = qx[front];
        y = qy[front];
        for (int i = 0; i < 4; ++i)
        {
            int tx = x + DIR_X[i];
            int ty = y + DIR_Y[i];
            if (isInside(tx, ty))
            {
                if (a[x][y] < a[tx][ty])
                {
                    way[tx][ty] += way[x][y];
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
        if (!isMaximum(x, y))
        {
            way[x][y] = 0;
        }
        visit[x][y] = false;
        if (++front >= MAXN * MAXN)
        {
            front = 0;
        }
    }
}

long long calc()
{
    memset(way, 0, sizeof(way));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (isMinimum(i, j))
            {
                bfs(i, j);
                #ifdef DEBUG
                printf("Minimum: %d %d\n", i, j);
                for (int ii = 0; ii < n; ++ii)
                {
                    printf("    ");
                    for (int jj = 0; jj < m; ++jj)
                    {
                        printf("%d ", way[ii][jj]);
                    }
                    printf("\n");
                }
                #endif // DEBUG
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            ans += way[i][j];
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                scanf("%d", &a[i][j]);
            }
        }
        printf("Case #%d: %lld\n", t, calc());
    }
    return 0;
}
