#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
const int DIR_Y[] = {1, 0, -1, 0};
const int DIR_X[] = {0, 1, 0, -1};

struct Animal
{
    int x, y;
    int dir;
    bool stopped;
    inline void input()
    {
        scanf("%d%d%d", &x, &y, &dir);
        stopped = false;
    }
    inline void left()
    {
        if (--dir < 0)
        {
            dir = 3;
        }
    }
    inline void right()
    {
        if (++dir > 3)
        {
            dir = 0;
        }
    }
} donkey, tiger;

int n;
bool visitD[MAXN][MAXN];
bool visitT[MAXN][MAXN];

bool valid(int x, int y, bool visit[MAXN][MAXN])
{
    if (x < 0 || x >= n || y < 0 || y >= n)
    {
        return false;
    }
    return !visit[x][y];
}

int main()
{
    while (scanf("%d", &n), n)
    {
        donkey.input();
        tiger.input();
        memset(visitD, false, sizeof(visitD));
        memset(visitT, false, sizeof(visitT));
        if (donkey.x == tiger.x && donkey.y == tiger.y)
        {
            donkey.stopped = true;
            tiger.stopped = true;
        }
        while (!donkey.stopped || !tiger.stopped)
        {
            visitD[donkey.x][donkey.y] = true;
            visitT[tiger.x][tiger.y] = true;
            if (!donkey.stopped)
            {
                int tx = donkey.x + DIR_X[donkey.dir];
                int ty = donkey.y + DIR_Y[donkey.dir];
                if (valid(tx, ty, visitD))
                {
                    donkey.x = tx;
                    donkey.y = ty;
                }
                else
                {
                    donkey.right();
                    tx = donkey.x + DIR_X[donkey.dir];
                    ty = donkey.y + DIR_Y[donkey.dir];
                    if (valid(tx, ty, visitD))
                    {
                        donkey.x = tx;
                        donkey.y = ty;
                    }
                    else
                    {
                        donkey.stopped = true;
                    }
                }
            }
            if (!tiger.stopped)
            {
                int tx = tiger.x + DIR_X[tiger.dir];
                int ty = tiger.y + DIR_Y[tiger.dir];
                if (valid(tx, ty, visitT))
                {
                    tiger.x = tx;
                    tiger.y = ty;
                }
                else
                {
                    tiger.left();
                    tx = tiger.x + DIR_X[tiger.dir];
                    ty = tiger.y + DIR_Y[tiger.dir];
                    if (valid(tx, ty, visitT))
                    {
                        tiger.x = tx;
                        tiger.y = ty;
                    }
                    else
                    {
                        tiger.stopped = true;
                    }
                }
            }
            if (donkey.x == tiger.x && donkey.y == tiger.y)
            {
                break;
            }
        }
        if (donkey.x == tiger.x && donkey.y == tiger.y)
        {
            printf("%d %d\n", donkey.x, donkey.y);
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}
