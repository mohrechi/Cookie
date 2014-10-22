#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
const int dirX[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dirY[] = {-1, 0, 1, -1, 1, -1, 0, 1};

int m, n;
char map[MAXN][MAXN];
int dist[MAXN][MAXN];
int sx, sy;
int ex, ey;

int qx[MAXN * MAXN];
int qy[MAXN * MAXN];
bool visit[MAXN][MAXN];

void spfa()
{
    memset(dist, -1, sizeof(dist));
    memset(visit, false, sizeof(visit));
    visit[sx][sy] = true;
    qx[0] = sx;
    qy[0] = sy;
    int front = 0, rear = 1;
    while(front != rear)
    {
        int x = qx[front];
        int y = qy[front];
        for(int k=0;k<8;++k)
        {
            int tx = x + dirX[k];
            int ty = y + dirY[k];
            while(tx >= 1 && tx <= m && ty >= 1 && ty <= n && map[tx][ty] != '*')
            {
                if(dist[tx][ty] == -1 || dist[tx][ty] > dist[x][y] + 1)
                {
                    dist[tx][ty] = dist[x][y] + 1;
                    if(!visit[tx][ty])
                    {
                        visit[tx][ty] = true;
                        qx[rear] = tx;
                        qy[rear] = ty;
                        if(++rear >= MAXN * MAXN)
                        {
                            rear = 0;
                        }
                    }
                }
                tx += dirX[k];
                ty += dirY[k];
            }
        }
        visit[x][y] = false;
        if(++front >= MAXN * MAXN)
        {
            front = 0;
        }
    }
}

int main()
{
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber--)
    {
        scanf("%d%d", &m, &n);
        memset(map, '*', sizeof(map));
        for(int i=1;i<=m;++i)
        {
            scanf("%s", map[i] + 1);
            for(int j=1;j<=n;++j)
            {
                if(map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                else if(map[i][j] == 'J')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        spfa();
        printf("%d\n", dist[ex][ey]);
    }
    return 0;
}
