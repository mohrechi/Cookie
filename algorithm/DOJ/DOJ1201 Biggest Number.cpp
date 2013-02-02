#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 35;
const int MAXM = MAXN * MAXN;
const int dirX[] = {0, 1, 0, -1};
const int dirY[] = {1, 0, -1, 0};

int n, m;
char map[MAXN][MAXN];
bool visit[MAXN][MAXN];

int len, state;
char ans[MAXN];
char cur[MAXN];

int qx[MAXM], qy[MAXM];
bool bVisit[MAXN][MAXN];

int bfs(int x, int y)
{
    int front = 0, rear = 1;
    memcpy(bVisit, visit, sizeof(visit));
    bVisit[x][y] = true;
    qx[0] = x, qy[0] = y;
    while(front < rear)
    {
        x = qx[front];
        y = qy[front];
        for(int i=0;i<4;++i)
        {
            int tx = x + dirX[i];
            int ty = y + dirY[i];
            if(!bVisit[tx][ty] && map[tx][ty] != '#')
            {
                bVisit[tx][ty] = true;
                qx[rear] = tx;
                qy[rear] = ty;
                ++ rear;
            }
        }
        ++ front;
    }
    return rear;
}

void dfs(int x, int y, int depth)
{
    cur[depth] = map[x][y];
    cur[depth + 1] = 0;
    int num = bfs(x, y);
    if(depth == 0)
    {
        if(cur[depth] > ans[depth])
        {
            state = 1;
        }
        else if(cur[depth] == ans[depth])
        {
            state = 0;
        }
        else
        {
            state = -1;
        }
    }
    if(num + depth < len)
    {
        return;
    }
    if(num + depth == len)
    {
        if(state == -1)
        {
            return;
        }
    }
    if(num == 1)
    {
        if(len > depth + 1)
        {
            return;
        }
        if(len == depth + 1 && strcmp(cur, ans) <= 0)
        {
            return;
        }
        len = depth + 1;
        strcpy(ans, cur);
        state = 0;
        return;
    }
    visit[x][y] = true;
    for(int i=0;i<4;++i)
    {
        int tx = x + dirX[i];
        int ty = y + dirY[i];
        if(!visit[tx][ty] && map[tx][ty] != '#')
        {
            if(state == 0)
            {
                if(map[tx][ty] > ans[depth + 1])
                {
                    state = 1;
                }
                else if(map[tx][ty] < ans[depth + 1])
                {
                    state = -1;
                }
                dfs(tx, ty, depth + 1);
                state = 0;
            }
            else
            {
                dfs(tx, ty, depth + 1);
            }
        }
    }
    visit[x][y] = false;
}

void dfs()
{
    len = 0;
    memset(ans, 0, sizeof(ans));
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(map[i][j] != '#')
            {
                memset(visit, false, sizeof(visit));
                state = 0;
                dfs(i, j, 0);
            }
        }
    }
}

int main()
{
    while(scanf("%d%d", &n, &m), n || m)
    {
        memset(map, '#', sizeof(map));
        for(int i=1;i<=n;++i)
        {
            scanf("%s", map[i] + 1);
            map[i][m + 1] = '#';
        }
        dfs();
        printf("%s\n", ans);
    }
    return 0;
}
