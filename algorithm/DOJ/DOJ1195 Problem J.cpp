#include <cstdio>
#include <cstring>
const int MAXN = 64;
const int dirX[] = {0, 1, 0, -1};
const int dirY[] = {1, 0, -1, 0};

char map[MAXN][MAXN];
int w, h;
bool visit[MAXN][MAXN];

void dfs(int x, int y)
{
    if(x >= 0 && x <= h+1)
        if(y >= 0 && y <= w+1)
            if(!visit[x][y] && map[x][y] == '.')
            {
                visit[x][y] = true;
                for(int i=0;i<4;++i)
                {
                    int tx = x + dirX[i];
                    int ty = y + dirY[i];
                    dfs(tx, ty);
                }
            }
}

int main()
{
    while(~scanf("%d%d", &w, &h))
    {
        for(int i=1;i<=h;++i)
        {
            scanf("%s", map[i] + 1);
        }
        for(int i=0;i<=w+1;++i)
        {
            map[0][i] = map[h+1][i] = '.';
        }
        for(int i=0;i<=h+1;++i)
        {
            map[i][0] = map[i][w+1] = '.';
        }
        int t, x1, y1, x2, y2;
        scanf("%d", &t);
        while(t--)
        {
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            if(map[x1][y1] == '.' || map[x2][y2] == '.' || map[x1][y1] != map[x2][y2] || (x1 == x2 && y1 == y2))
            {
                printf("NO\n");
            }
            else
            {
                char temp = map[x1][y1];
                map[x1][y1] = map[x2][y2] = '.';
                memset(visit, false, sizeof(visit));
                dfs(x1, y1);
                if(visit[x2][y2])
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                    map[x1][y1] = map[x2][y2] = temp;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
