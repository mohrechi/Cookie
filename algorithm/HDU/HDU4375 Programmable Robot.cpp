#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXL = 1024;
const int MAXN = 1000010;

const int dirX[] = {-1, 0, 1, 0};
const int dirY[] = {0, 1, 0, -1};

int h, w, n;
int sx, sy;
int ex, ey;
char map[MAXL][MAXL];
char instruction[MAXN];
bool visit[MAXL][MAXL][4];
int dir[MAXN], link[MAXN][4];
int head[MAXN], next[MAXL * MAXL * 4];

inline bool isInside(const int &x, const int &y, const int &d)
{
    if(x >= 0)
        if(x < h)
            if(y >= 0)
                if(y < w)
                    if(map[x][y] == '.')
                        if(!visit[x][y][d])
                            return true;
    return false;
}

inline int getPos(const int &x, const int &y, const int &d)
{
    return ((x * w) << 2) + (y << 2) + d;
}

inline int getX(const int &pos)
{
    return (pos >> 2) / w;
}

inline int getY(const int &pos)
{
    return (pos >> 2) % w;
}

void init()
{
    dir[0] = 0;
    for(int i=0;i<n;++i)
    {
        if(instruction[i] == 'L')
        {
            dir[i + 1] = (dir[i] + 3) % 4;
        }
        else
        {
            dir[i + 1] = (dir[i] + 1) % 4;
        }
    }
    int h[4];
    memset(h, -1, sizeof(h));
    for(int i=n;i>=0;--i)
    {
        for(int j=0;j<4;++j)
        {
            link[i][j] = h[j];
        }
        h[dir[i]] = i;
    }
}

inline bool push(int s, int x, int y, int d)
{
    while(isInside(x, y, d))
    {
        if(x == ex && y == ey)
        {
            return true;
        }
        visit[x][y][d] = true;
        next[getPos(x, y, d)] = head[s];
        head[s] = getPos(x, y, d);
        x += dirX[d];
        y += dirY[d];
    }
    return false;
}

bool bfs()
{
    memset(head, -1, sizeof(head));
    memset(visit, false, sizeof(visit));
    if(push(0, sx, sy, 0))
    {
        return true;
    }
    for(int i=0;i<=n;++i)
    {
        for(int j=head[i];j!=-1;j=next[j])
        {
            int x = getX(j);
            int y = getY(j);
            for(int k=0;k<4;++k)
            {
                if(link[i][k] != -1)
                {
                    if(push(link[i][k], x, y, k))
                    {
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main()
{
    while(~scanf("%d%d%d", &h, &w, &n))
    {
        scanf("%s", instruction);
        for(int i=0;i<h;++i)
        {
            scanf("%s", map[i]);
            for(int j=0;j<w;++j)
            {
                if(map[i][j] == 'S')
                {
                    sx = i, sy = j;
                    map[i][j] = '.';
                }
                else if(map[i][j] == 'E')
                {
                    ex = i, ey = j;
                    map[i][j] = '.';
                }
            }
        }
        init();
        if(bfs())
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
